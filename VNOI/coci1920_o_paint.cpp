//-----------------------------------------------------------------------------------
			My code is under this, this just solve i copy
-----------------------------------------------------------------------------------//

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int MAXPIXELS = 300000;
const int MAGIC = 400;

int n, m;

// Pomocna klasa koja pretvara 1D niz u 2D matricu dimenzije n x m.
template<class T>
class Array2d {
 public:
  T *operator[](size_t index) { return &data[index * m]; }

 private:
  T data[MAXPIXELS];
};

Array2d<int> mat;
Array2d<bool> vis;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

struct Component {
  int id;
  int color;
  bool large;
  vector<pair<int, int>> pixels;
  vector<int> larges;
  map<int, vector<int>> by_color;
};

vector<Component> C;

Array2d<int> comp_id;
int comp_visited[MAXPIXELS];  // koristi se s cookiejem
int comp_visited_cookie = 0;
int parent[MAXPIXELS];

int RealId(int comp) {
  if (parent[comp] == comp) return comp;
  return parent[comp] = RealId(parent[comp]);
}

void TraverseNeighbors(int id, function<void(int)> callback) {
  comp_visited_cookie++;
  for (const auto &pt : C[id].pixels) {
    for (int i = 0; i < 4; ++i) {
      int nx = pt.x + dx[i];
      int ny = pt.y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      int nid = comp_id[nx][ny];
      if (nid != id && comp_visited[nid] != comp_visited_cookie) {
        callback(nid);
        comp_visited[nid] = comp_visited_cookie;
      }
    }
  }
}

vector<int> GetNeighborsByColor(int id, int color) {
  vector<int> ret;
  auto &comp = C[id];
  if (comp.large) {
    comp_visited_cookie++;
    for (const auto &nid_temp : comp.by_color[color]) {
      int nid = RealId(nid_temp);
      if (nid != id && C[nid].color == color &&
          comp_visited[nid] != comp_visited_cookie) {
        ret.push_back(nid);
        comp_visited[nid] = comp_visited_cookie;
      }
    }
    comp.by_color[color].clear();  /// <------
  } else {
    TraverseNeighbors(id, [&ret, color](int nid) {
      if (C[nid].color == color) ret.push_back(nid);
    });
  }
  return ret;
}

void DeclareLarge(int id) {
  C[id].large = true;
  TraverseNeighbors(id, [id](int nid) {
    C[nid].larges.push_back(id);
    C[id].by_color[C[nid].color].push_back(nid);
  });
}

void TraverseLarges(int id, function<void(int)> callback) {
  comp_visited_cookie++;
  for (const auto &nid_temp : C[id].larges) {
    int nid = RealId(nid_temp);
    if (nid != id && C[nid].large && comp_visited[nid] != comp_visited_cookie) {
      callback(nid);
      comp_visited[nid] = comp_visited_cookie;
    }
  }
}

void NeutralizeLarges(int id) {
  vector<int> new_larges;
  TraverseLarges(id, [&new_larges](int nid) { new_larges.push_back(nid); });
  C[id].larges.swap(new_larges);
}

int Merge(int id1, int id2) {
  if (!C[id1].large && C[id2].large) DeclareLarge(id1);
  if (C[id1].large && !C[id2].large) DeclareLarge(id2);

  // Spoji piksele
  if (C[id1].pixels.size() > C[id2].pixels.size()) swap(id1, id2);
  int nid = id2;
  parent[id1] = id2;
  for (const auto &pt : C[id1].pixels)
    comp_id[pt.x][pt.y] = nid;
  for (const auto &pixel : C[id1].pixels)
    C[id2].pixels.push_back(pixel);
  vector<pair<int, int>>().swap(C[id1].pixels);

  // Spoji listu velikih susjeda
  if (C[id1].larges.size() > C[id2].larges.size())
    C[id1].larges.swap(C[id2].larges);
  for (const auto &l : C[id1].larges)
    C[id2].larges.push_back(l);
  vector<int>().swap(C[id1].larges);
  NeutralizeLarges(id2);

  // Spoji susjede po bojama
  if (C[id1].by_color.size() > C[id2].by_color.size())
    C[id1].by_color.swap(C[id2].by_color);
  for (auto &entry : C[id1].by_color) {
    int color = entry.first;
    auto &list1 = entry.second;
    auto &list2 = C[id2].by_color[color];
    if (list1.size() > list2.size()) list1.swap(list2);
    for (const auto &el : list1)
      list2.push_back(el);
    vector<int>().swap(list1);
  }

  if (!C[nid].large && C[nid].pixels.size() > MAGIC)
    DeclareLarge(nid);

  return nid;
}

void Fill(int x, int y, int color) {
  int id = comp_id[x][y];
  C[id].color = color;
  for (const auto &nid : GetNeighborsByColor(id, color)) {
    id = Merge(id, nid);
  }
  TraverseLarges(id, [id, color](int nid) {
    C[nid].by_color[color].push_back(id);
  });
}

////////////////////////////////////////////////////////////////////////////////
// Initial processing

vector<pair<int, int>> traversal;

void FindComponent(int x, int y, int color) {
  if (x < 0 || y < 0 || x >= n || y >= m) return;
  if (mat[x][y] != color) return;
  if (vis[x][y]) return;
  vis[x][y] = true;
  traversal.emplace_back(x, y);
  for (int i = 0; i < 4; ++i) {  
    FindComponent(x + dx[i], y + dy[i], color);
  }
}

void Init() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j]) continue;
      traversal.clear();
      FindComponent(i, j, mat[i][j]);
      Component comp;
      comp.id = C.size();
      comp.color = mat[i][j];
      comp.large = false;
      comp.pixels = traversal;
      C.push_back(comp);
      for (const auto &pt : comp.pixels)
        comp_id[pt.x][pt.y] = comp.id;
    }
  }
  iota(parent, parent + n * m, 0);
  for (auto &comp : C) {
    if (comp.pixels.size() > MAGIC)
      DeclareLarge(comp.id);
  }
}

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  Init();

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x, y, color;
    cin >> x >> y >> color;
    Fill(x - 1, y - 1, color);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << C[comp_id[i][j]].color << " \n"[j + 1 == m];
    }
  }
  
  return 0;
}


//-----------------------------------------------------------------------------------
				My code still TLE
-----------------------------------------------------------------------------------//

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct dsu{
    vector<vector<int>> color, sz;
    vector<vector<pii>> par;
    vector<vector<set<pii>>> adj;
    dsu(int n, int m): par(n, vector<pii>(m)), sz(n, vi(m)), color(n, vi(m)), adj(n, vector<set<pii>>(m)) {};
    void make_set(){
        for(int i = 0; i < par.size(); i++)
            for(int j = 0; j < par[i].size(); j++)
                par[i][j] = {i, j}, sz[i][j] = 1, color[i][j] = 0;
    }
    pii find(pii v){
        if(v == par[v.fi][v.se])
            return v;
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }
    void Union(pii a, pii b){
        a = find(a);
        b = find(b);
        if(a != b){
            // if(sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a, b);
            // sz[a.fi][a.se] += sz[b.fi][b.se];
            if(adj[a.fi][a.se].size() < adj[b.fi][b.se].size()) 
                swap(a, b);
            sz[a.fi][a.se] += sz[b.fi][b.se];
            for(auto it : adj[b.fi][b.se])
                if(it != a)
                    adj[a.fi][a.se].insert(it);
            par[b.fi][b.se] = a;            
        }
    }
    void change_color(pii u, int c, int n, int m){
        u = find(u);
        color[u.fi][u.se] = c;
        for(auto it : adj[u.fi][u.se]){
            if(color[u.fi][u.se] == color[it.fi][it.se])
                Union(u, it);
        }
    }
    void check_adj(int n, int m){
        auto checkValid = [&](pii t){
            if(t.fi >= 0 && t.fi < n && t.se >= 0 && t.se < m)
                return true;
            else
                return false;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 4; k++){
                    pii u = {i+dx[k], j+dy[k]};
                    if(checkValid(u) && par[u.fi][u.se] != par[i][j]){
                        adj[par[i][j].fi][par[i][j].se].insert(par[u.fi][u.se]);
                        adj[par[u.fi][u.se].fi][par[u.fi][u.se].se].insert(par[i][j]);
                    }
                }
            }
        }
    }
};

void bfs(pii start, int n, int m, vector<vi> &a, vector<vi> &vis, dsu &g){
    auto checkValid = [&](pii t){
        if(t.fi >= 0 && t.fi < n && t.se >= 0 && t.se < m)
            return true;
        else
            return false;
    };
    // cout << start.fi << " " << start.se << '\n';
    queue<pii> q;
    vis[start.fi][start.se] = 1;
    q.push(start);
    while(!q.empty()){
        pii v = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pii u = {v.fi+dx[i], v.se+dy[i]};
            if(checkValid(u) && !vis[u.fi][u.se]){
                if(a[u.fi][u.se] == a[start.fi][start.se]){
                    g.Union(start, u);
                    q.push(u);
                    vis[u.fi][u.se] = 1;
                }
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    vector<vi> vis(n, vi(m, 0));
    dsu g(n, m);
    g.make_set();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            g.color[i][j] = a[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(!vis[i][j])
                bfs({i, j}, n, m, a, vis, g);
    }
    g.check_adj(n, m);


    int q; cin >> q;
    while(q--){
        int x, y, c; cin >> x >> y >> c;
        g.change_color({x-1, y-1}, c, n, m);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         pii pos = g.find({i, j});
        //         cout << g.color[pos.fi][pos.se] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pii pos = g.find({i, j});
            cout << g.color[pos.fi][pos.se] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

