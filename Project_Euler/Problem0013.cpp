#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int BASE_DIGITS = 1;
const int BASE = 10;

class BigInt {
public:
    int sign;
    vector<uint32_t> digit;

    BigInt(): sign(1) {}

    BigInt(const string &s) { *this = s; }

    BigInt(int64_t val) { *this = val; }

    BigInt &operator = (const BigInt &b) {
        sign = b.sign;
        digit = b.digit;
        return *this;
    }

    BigInt &operator = (const string &s) {
        read(s);
        return *this;
    }

    BigInt &operator = (int64_t val) {
        sign = val >= 0 ? 1 : -1;
        val = llabs(val);
        digit.clear();
        for (; val; val /= BASE) {
            digit.push_back(val % BASE);
        }
        trim();
        return *this;
    }

    BigInt &operator += (const BigInt &b) {
        if (sign != b.sign) {
            BigInt t = b;
            t.sign *= -1;
            return *this -= t;
        }
        int carry = 0, len = (int)max(size(), b.size());
        for (int i = 0; i < len; i++) {
            int sum = carry;
            if (i < (int)size()) sum += digit[i];
            if (i < (int)b.size()) sum += b[i];
            if (i < (int)size()) digit[i] = sum % BASE;
            else digit.push_back(sum % BASE);
            carry = sum / BASE;
        }
        if (carry) digit.push_back(carry);
        trim();
        return *this;
    }

    BigInt &operator -= (const BigInt &b) {
        if (sign != b.sign) {
            return *this += (-b);
        }
        if (__compare_abs(b) == -1) {
            BigInt t = b;
            t -= *this;
            t.sign *= -1;
            return *this = t;
        }
        int borrow = 0, len = (int)max(size(), b.size());
        for (int i = 0; i < len; i++) {
            int sub = -borrow;
            if (i < (int)size()) sub += digit[i];
            if (i < (int)b.size()) sub -= b[i];
            if (sub < 0) sub += BASE, borrow = 1;
            else borrow = 0;
            digit[i] = sub;
        }
        trim();
        return *this;
    }

    BigInt &operator *= (const BigInt &b) {
        return *this = karatsuba(*this, b);
    }

    BigInt &operator /= (const BigInt &b) {
        *this = divmod(*this, b).first;
        return *this;
    }

    BigInt &operator %= (const BigInt &b) {
        *this = divmod(*this, b).second;
        return *this;
    }

    // ------------------------ Operator ------------------------
    // BigInt += Int
    BigInt &operator += (int64_t t) { return *this += BigInt(t); }
    BigInt &operator -= (int64_t t) { return *this -= BigInt(t); }
    BigInt &operator *= (int64_t t) { return *this *= BigInt(t); }
    BigInt &operator /= (int64_t t) { 
        assert(t != 0); // not divided for 0
        int64_t rem = 0;
        for (int i = (int)size() - 1; i >= 0; i--) {
            int64_t cur = rem * BASE + (*this)[i];
            (*this)[i] = uint32_t(cur / t);
            rem = cur % t;
        } 
        trim();
        sign = sign * (t < 0 ? -1 : 1);
        return *this;
    }
    BigInt &operator %= (int64_t t) {
        assert(t != 0);
        int64_t rem = 0;
        for (int i = (int)size() - 1; i >= 0; i--) {
            int64_t cur = rem * BASE + (*this)[i];
            rem = cur % t;
        }
        if (rem < 0) rem += llabs(t);
        int s = sign;
        *this = rem;
        sign = s;
        return *this;
    }

    BigInt operator - () const { BigInt res = *this; res *= -1; return res; } // -a;
    BigInt operator + () const { return BigInt(*this); } // +a;
    BigInt &operator ++ () { *this += 1; return *this; } // ++a;
    BigInt &operator -- () { *this -= 1; return *this; } // --a;
    BigInt operator ++ (int) { BigInt res = *this; *this += 1; return res; } // a++;
    BigInt operator -- (int) { BigInt res = *this; *this -= 1; return res; } // a--;

    // BigInt = BigInt + BigInt
    BigInt operator + (const BigInt &b) const { return BigInt(*this) += b; }
    BigInt operator - (const BigInt &b) const { return BigInt(*this) -= b; }
    BigInt operator * (const BigInt &b) const { return BigInt(*this) *= b; }
    BigInt operator / (const BigInt &b) const { return BigInt(*this) /= b; }
    BigInt operator % (const BigInt &b) const { return BigInt(*this) %= b; }

    // BigInt = BigInt + Int
    BigInt operator + (int64_t t) const { return BigInt(*this) += t; }
    BigInt operator - (int64_t t) const { return BigInt(*this) -= t; }
    BigInt operator * (int64_t t) const { return BigInt(*this) *= t; }
    BigInt operator / (int64_t t) const { return BigInt(*this) /= t; }
    BigInt operator % (int64_t t) const { return BigInt(*this) %= t; }

    // BigInt = Int + BigInt
    friend BigInt operator + (int64_t t, const BigInt &b) { BigInt res(t); res += b; return res; }
    friend BigInt operator - (int64_t t, const BigInt &b) { BigInt res(t); res -= b; return res; }
    friend BigInt operator * (int64_t t, const BigInt &b) { BigInt res(t); res *= b; return res; }
    friend BigInt operator / (int64_t t, const BigInt &b) { BigInt res(t); res /= b; return res; }
    friend BigInt operator % (int64_t t, const BigInt &b) { BigInt res(t); res %= b; return res; }

    uint32_t operator [] (const int i) const { assert(i >= 0 && i < (int)size()); return digit[i]; }
    uint32_t &operator [] (const int i) { assert(i >= 0 && i < (int)size()); return digit[i]; }

    // ------------------------- Comparison ---------------------
    bool operator < (const BigInt &b) const {
        if (sign != b.sign) {
            return sign < b.sign;
        }
        if (size() != b.size()) {
            return size() * sign < b.size() * b.sign;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] * sign < b[i] * sign;
            }
        }
        return false;
    }

    bool operator > (const BigInt &b) const { return b < *this; }
    bool operator <= (const BigInt &b) const { return !(b < *this); }
    bool operator >= (const BigInt &b) const { return !(*this < b); }
    bool operator == (const BigInt &b) const { return !(*this < b) && !(b < *this); }
    bool operator != (const BigInt &b) const { return *this < b || b < *this; }

    bool operator == (int64_t t) const { return *this == BigInt(t); }
    bool operator != (int64_t t) const { return *this != BigInt(t); }
    bool operator < (int64_t t) const { return *this < BigInt(t); }
    bool operator <= (int64_t t) const { return *this <= BigInt(t); }
    bool operator > (int64_t t) const { return *this > BigInt(t); }
    bool operator >= (int64_t t) const { return *this >= BigInt(t); }

    // 0 if |a| == |b|
    // -1 if |a| < |b|
    // 1 if |a| > |b|
    int __compare_abs(const BigInt &b) const {
        if (size() != b.size()) {
            return size() < b.size() ? -1 : 1;
        }
        for (int i = (int)size() - 1; i >= 0; i--) {
            if ((*this)[i] != b[i]) {
                return (*this)[i] < b[i] ? -1 : 1;
            }
        }
        return 0;
    }

    // -------------------- karatsuba ---------------------
    BigInt mul_simple(const BigInt &a, const BigInt &b) {
        BigInt x = a, y = b;
        BigInt res;
        res.sign = x.sign * y.sign;
        res.digit.resize(x.size() + y.size());
        for (int i = 0; i < (int)x.size(); i++) {
            uint64_t carry = 0;
            for (int j = 0; j < (int)y.size(); j++) {
                uint64_t cur = res[i+j] + carry;
                cur += 1ull * x[i] * y[j];
                res[i+j] = cur % BASE;
                carry = cur / BASE;
            }
            if (carry) res[i+(int)y.size()] += carry;
        }
        res.trim();
        if (res.isZero()) res.sign = 1;
        return res;
    }

    BigInt shifted(int k) const {
        if (isZero()) return *this;
        BigInt r = *this;
        r.digit.insert(r.digit.begin(), k, 0);
        return r;
    }

    BigInt karatsuba(const BigInt &a, const BigInt &b) {
        if (a.size() < 32 || b.size() < 32) {
            return mul_simple(a, b);
        }
        size_t n = max(a.size(), b.size());
        size_t k = n / 2;

        BigInt a_low, a_high, b_low, b_high;
        int m1 = min(k, a.size()), m2 = min(k, b.size());
        a_low.digit.assign(a.digit.begin(), a.digit.begin() + m1);
        a_high.digit.assign(a.digit.begin() + m1, a.digit.end());
        b_low.digit.assign(b.digit.begin(), b.digit.begin() + m2);
        b_high.digit.assign(b.digit.begin() + m2, b.digit.end());
        a_low.sign = a_high.sign = b_low.sign = b_high.sign = 1;
        a_low.trim(); a_high.trim();
        b_low.trim(); b_high.trim();

        BigInt z0 = karatsuba(a_low, b_low);
        BigInt z1 = karatsuba(a_high, b_high);
        BigInt z2 = karatsuba(a_low + a_high, b_low + b_high) - z1 - z0;
        BigInt res = z1.shifted(2 * k) + z2.shifted(k) + z0;
        res.trim();
        res.sign = (a.sign != b.sign ? -1 : 1);
        return res;
    }

    // ------------------------ Div / Mod -----------------------
    pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
        assert(b1 != 0); // not divided for 0
        ll norm = BASE / (b1.digit.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q = 0, r = 0;
        q.digit.resize(a.size());

        for (int i = a.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += a[i];
            int64_t s1 = r.size() <= b.size() ? 0 : r[b.size()];
            int64_t s2 = r.size() <= b.size() - 1 ? 0 : r[b.size() - 1];
            int64_t d = (BASE * s1 + s2) / b.digit.back();
            if (d >= BASE) {
                d = BASE - 1;
            }
            r -= b * d;
            while (r < 0) {
                r += b, --d;
            }
            q[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim(); r.trim();

        BigInt remainder;
        remainder.digit.resize(r.size());
        int64_t carry = 0;
        for (int i = (int)r.size() - 1; i >= 0; i--) {
            int64_t cur = r[i] + carry * BASE;
            remainder[i] = cur / norm;
            carry = cur % norm;
        }
        remainder.trim();
        auto res = make_pair(q, remainder);
        if (res.second < 0) {
            res.second += b1.abs();
        }
        return res;
    }

    // ------------------------- Misc ---------------------------
    size_t size() const { return digit.size(); }

    bool isZero() const { return digit.empty(); }

    void trim() {
        while (!digit.empty() && !digit.back()) {
            digit.pop_back();
        }
        if (digit.empty()) sign = 1;
    }

    BigInt abs() const { BigInt res = *this; res.sign = 1; return res; }

    string toString() const {
        ostringstream oss;
        oss << *this;
        return oss.str();
    }

    // only support b >= 0, if b < 0 need to implement modulo inverse
    friend BigInt pow(const BigInt &a, const BigInt &b, ll mod) { return pow(a, b, BigInt(mod)); }
    friend BigInt pow(const BigInt &a, const BigInt &b, const BigInt &mod) {
        BigInt x(a), y(b), res(1);
        while (y != 0) {
            if (y[0] % 2 == 1) res = res * x % mod;
            x = x * x % mod;
            y /= 2;
        }
        return res;
    }

    friend BigInt __gcd(const BigInt &a, const BigInt &b) {
        if (b == 0) return a;
        return __gcd(b, a % b);
    }

    friend BigInt __lcm(const BigInt &a, const BigInt &b) {
        return a / __gcd(a, b) * b;
    }

    // safe sqrt for long long and BigInt
    friend BigInt sqrt(const BigInt &a1) {
        BigInt a = a1;
        while (a.digit.empty() || a.size() % 2 == 1) {
            a.digit.push_back(0);
        }

        int n = a.size();
        int firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);
        int norm = BASE / (firstDigit + 1);
        a = a * norm * norm;
        while (a.digit.empty() || a.size() % 2 == 1) {
            a.digit.push_back(0);
        }

        BigInt r = 1ll * a[n - 1] * BASE + a[n - 2];
        firstDigit = (int) sqrt((double) a[n - 1] * BASE + a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for (int j = n / 2 - 1; j >= 0; j--) {
            for (; ; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE) * BigInt(BASE);
                r1 += (j > 0 ? 1ll * a[2 * j - 1] * BASE + a[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= BASE;
            res += q;

            if (j > 0) {
                int d1 = res.size() + 2 < r.size() ? r[res.size() + 2] : 0;
                int d2 = res.size() + 1 < r.size() ? r[res.size() + 1] : 0;
                int d3 = res.size() < r.size() ? r[res.size()] : 0;
                q = (1ll * d1 * BASE * BASE + 1ll * d2 * BASE + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }

    // ---------------------- Input Output ---------------------
    /* only use for decimal number */
    void read(const string &s) {
        sign = (s[0] == '-' ? -1 : 1);
        digit.clear();
        int pos = (s[0] == '-' ? 1 : 0);
        for (int i = (int)s.size() - 1; i >= pos; i -= BASE_DIGITS) {
            int x = 0;
            int k = max(pos, i - BASE_DIGITS + 1);
            for (int j = k; j <= i; j++) {
                x = x * 10 + (s[j] - '0');
            }
            digit.push_back(x);
        }
        trim();
    }

    friend istream &operator >> (istream &in, BigInt &a) {
        string s; in >> s;
        a.read(s);
        return in;
    }

    friend ostream &operator << (ostream &out, const BigInt &a) {
        if (a.sign == -1 && !a.isZero()) out << '-';
        out << (a.digit.empty() ? 0 : a.digit.back());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            out << setw(BASE_DIGITS) << setfill('0') << a[i];
        return out;
    }
};

string s =  "37107287533902102798797998220837590246510135740250\n"
            "46376937677490009712648124896970078050417018260538\n"
            "74324986199524741059474233309513058123726617309629\n"
            "91942213363574161572522430563301811072406154908250\n"
            "23067588207539346171171980310421047513778063246676\n"
            "89261670696623633820136378418383684178734361726757\n"
            "28112879812849979408065481931592621691275889832738\n"
            "44274228917432520321923589422876796487670272189318\n"
            "47451445736001306439091167216856844588711603153276\n"
            "70386486105843025439939619828917593665686757934951\n"
            "62176457141856560629502157223196586755079324193331\n"
            "64906352462741904929101432445813822663347944758178\n"
            "92575867718337217661963751590579239728245598838407\n"
            "58203565325359399008402633568948830189458628227828\n"
            "80181199384826282014278194139940567587151170094390\n"
            "35398664372827112653829987240784473053190104293586\n"
            "86515506006295864861532075273371959191420517255829\n"
            "71693888707715466499115593487603532921714970056938\n"
            "54370070576826684624621495650076471787294438377604\n"
            "53282654108756828443191190634694037855217779295145\n"
            "36123272525000296071075082563815656710885258350721\n"
            "45876576172410976447339110607218265236877223636045\n"
            "17423706905851860660448207621209813287860733969412\n"
            "81142660418086830619328460811191061556940512689692\n"
            "51934325451728388641918047049293215058642563049483\n"
            "62467221648435076201727918039944693004732956340691\n"
            "15732444386908125794514089057706229429197107928209\n"
            "55037687525678773091862540744969844508330393682126\n"
            "18336384825330154686196124348767681297534375946515\n"
            "80386287592878490201521685554828717201219257766954\n"
            "78182833757993103614740356856449095527097864797581\n"
            "16726320100436897842553539920931837441497806860984\n"
            "48403098129077791799088218795327364475675590848030\n"
            "87086987551392711854517078544161852424320693150332\n"
            "59959406895756536782107074926966537676326235447210\n"
            "69793950679652694742597709739166693763042633987085\n"
            "41052684708299085211399427365734116182760315001271\n"
            "65378607361501080857009149939512557028198746004375\n"
            "35829035317434717326932123578154982629742552737307\n"
            "94953759765105305946966067683156574377167401875275\n"
            "88902802571733229619176668713819931811048770190271\n"
            "25267680276078003013678680992525463401061632866526\n"
            "36270218540497705585629946580636237993140746255962\n"
            "24074486908231174977792365466257246923322810917141\n"
            "91430288197103288597806669760892938638285025333403\n"
            "34413065578016127815921815005561868836468420090470\n"
            "23053081172816430487623791969842487255036638784583\n"
            "11487696932154902810424020138335124462181441773470\n"
            "63783299490636259666498587618221225225512486764533\n"
            "67720186971698544312419572409913959008952310058822\n"
            "95548255300263520781532296796249481641953868218774\n"
            "76085327132285723110424803456124867697064507995236\n"
            "37774242535411291684276865538926205024910326572967\n"
            "23701913275725675285653248258265463092207058596522\n"
            "29798860272258331913126375147341994889534765745501\n"
            "18495701454879288984856827726077713721403798879715\n"
            "38298203783031473527721580348144513491373226651381\n"
            "34829543829199918180278916522431027392251122869539\n"
            "40957953066405232632538044100059654939159879593635\n"
            "29746152185502371307642255121183693803580388584903\n"
            "41698116222072977186158236678424689157993532961922\n"
            "62467957194401269043877107275048102390895523597457\n"
            "23189706772547915061505504953922979530901129967519\n"
            "86188088225875314529584099251203829009407770775672\n"
            "11306739708304724483816533873502340845647058077308\n"
            "82959174767140363198008187129011875491310547126581\n"
            "97623331044818386269515456334926366572897563400500\n"
            "42846280183517070527831839425882145521227251250327\n"
            "55121603546981200581762165212827652751691296897789\n"
            "32238195734329339946437501907836945765883352399886\n"
            "75506164965184775180738168837861091527357929701337\n"
            "62177842752192623401942399639168044983993173312731\n"
            "32924185707147349566916674687634660915035914677504\n"
            "99518671430235219628894890102423325116913619626622\n"
            "73267460800591547471830798392868535206946944540724\n"
            "76841822524674417161514036427982273348055556214818\n"
            "97142617910342598647204516893989422179826088076852\n"
            "87783646182799346313767754307809363333018982642090\n"
            "10848802521674670883215120185883543223812876952786\n"
            "71329612474782464538636993009049310363619763878039\n"
            "62184073572399794223406235393808339651327408011116\n"
            "66627891981488087797941876876144230030984490851411\n"
            "60661826293682836764744779239180335110989069790714\n"
            "85786944089552990653640447425576083659976645795096\n"
            "66024396409905389607120198219976047599490197230297\n"
            "64913982680032973156037120041377903785566085089252\n"
            "16730939319872750275468906903707539413042652315011\n"
            "94809377245048795150954100921645863754710598436791\n"
            "78639167021187492431995700641917969777599028300699\n"
            "15368713711936614952811305876380278410754449733078\n"
            "40789923115535562561142322423255033685442488917353\n"
            "44889911501440648020369068063960672322193204149535\n"
            "41503128880339536053299340368006977710650566631954\n"
            "81234880673210146739058568557934581403627822703280\n"
            "82616570773948327592232845941706525094512325230608\n"
            "22918802058777319719839450180888072429661980811197\n"
            "77158542502016545090413245809786882778948721859617\n"
            "72107838435069186155435662884062257473692284509516\n"
            "20849603980134001723930671666823555245252804609722\n"
            "53503534226472524250874054075591789781264330331690\n";

void solve1() {
    stringstream ss(s);
    string t;
    vector<BigInt> bigNum;
    while (getline(ss, t, '\n')) {
        bigNum.push_back(BigInt(t));
    }
    BigInt ans = 0;
    for (BigInt &x : bigNum) ans += x;
    cout << ans;
}

int main() {
    solve1();
    return 0;
}