# C++ 코딩테스트 완전 참고서 (표준 라이브러리 STL 온리)

> 코딩테스트 중 막힐 때 이 파일 하나만 보고 해결하기 위한 레퍼런스.
> 각 항목은 **「언제 쓰나 → 복붙 가능 코드 → 시간복잡도」** 3단 구조.
> 모든 코드는 `<bits/stdc++.h>` 기반이며, g++ -std=c++17 -O2 기준이다.

---

## 📑 목차 (Ctrl+F 로 검색)

| 섹션 | 키워드 검색 |
|------|------------|
| [0. 빠른 참조 치트시트](#0-빠른-참조-치트시트) | `#cheat` |
| [1. 기본 템플릿 & 빠른 입출력](#1-기본-템플릿--빠른-입출력) | `#template` |
| [2. STL 자료구조](#2-stl-자료구조) | `#stl` |
| [3. STL 알고리즘 함수](#3-stl-알고리즘-함수) | `#algo` |
| [4. 문자열 처리](#4-문자열-처리) | `#string` |
| [5. 수학 / 정수론](#5-수학--정수론) | `#math` |
| [6. 순열 / 조합](#6-순열--조합) | `#perm` |
| [7. 누적합 / 구간합](#7-누적합--구간합) | `#prefix` |
| [8. 완전탐색 & 백트래킹](#8-완전탐색--백트래킹) | `#brute` |
| [9. 그래프 표현](#9-그래프-표현) | `#graph` |
| [10. DFS / BFS](#10-dfs--bfs) | `#dfs` `#bfs` |
| [11. 트리 순회](#11-트리-순회) | `#tree` |
| [12. 정렬 응용](#12-정렬-응용-struct-비교-pq) | `#sort` |
| [13. 이분탐색](#13-이분탐색) | `#binary` |
| [14. 투포인터 / 슬라이딩윈도우](#14-투포인터--슬라이딩-윈도우) | `#twopointer` |
| [15. 그리디](#15-그리디) | `#greedy` |
| [16. 동적계획법 DP](#16-동적계획법-dp) | `#dp` |
| [17. 최단경로](#17-최단경로) | `#shortest` |
| [18. 유니온파인드](#18-유니온파인드서로소-집합) | `#uf` |
| [19. 비트마스킹](#19-비트마스킹) | `#bit` |
| [20. 실전 팁 & 맞왜틀 체크리스트](#20-실전-팁--맞왜틀-체크리스트) | `#tips` |

---

## 0. 빠른 참조 치트시트
<a id="cheat"></a>

**시간복잡도별 처리 가능 N (1초 기준, 약 1억회 연산):**

| 복잡도 | 최대 N |
|--------|--------|
| O(N!) | 10 |
| O(2^N) | 20~25 |
| O(N^3) | 500 |
| O(N^2) | 5,000 |
| O(N log N) | 1,000,000 |
| O(N) | 10,000,000 |

**자료형 범위 (외우기):**

| 타입 | 범위 |
|------|------|
| `int` | ±21억 (2.1×10⁹) |
| `long long` | ±9.2×10¹⁸ |
| `unsigned long long` | 1.8×10¹⁹ |
| `double` | ±1.7×10³⁰⁸ (유효숫자 15자리) |

**INF 값 설정:** `const int INF = 1e9;` 또는 `987654321;`

**자주 헷갈리는:**
- `int × int` → 오버플로 주의! 큰 수 곱할 때 `(long long)a * b` 캐스팅
- `1e9`는 double 리터럴이지만 int로 암묵 변환됨 (정확히 1000000000)
- 나눗셈 결과 실수 필요시 `1.0 * a / b` 또는 `(double)a / b`

---

## 1. 기본 템플릿 & 빠른 입출력
<a id="template"></a>

### 1.1 표준 템플릿 (복붙해서 시작)
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 코드 작성
    
    return 0;
}
```

### 1.2 빠른 입출력 (필수!)
**cin/cout 속도 = scanf/printf 속도로 만들기:**
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// cout.tie(NULL);  // 출력 많을 때만 추가
```

**주의:** sync 끄면 `scanf/printf`와 `cin/cout` 섞어 쓰면 안 됨!

### 1.3 입력 방법별
```cpp
// 정수/문자열 (공백/개행 구분)
int n; string s;
cin >> n >> s;

// 한 줄 통째로 (공백 포함)
string line;
getline(cin, line);

// cin 다음에 getline 쓸 때: 버퍼 비우기 필수!
int T;
cin >> T;
cin.ignore();              // 또는 string buf; getline(cin, buf);
while(T--) {
    string s;
    getline(cin, s);
}

// scanf로 따닥따닥 붙은 숫자 입력 ("1234"를 1,2,3,4로)
int a, b, c, d;
scanf("%1d %1d %1d %1d", &a, &b, &c, &d);

// 입력 끝이 정해지지 않은 경우 (EOF)
int x;
while(scanf("%d", &x) != EOF) { /* ... */ }
while(cin >> x) { /* ... */ }

// 2차원 배열 입력
int n, m, a[104][104];
cin >> n >> m;
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> a[i][j];
```

### 1.4 출력 방법별
```cpp
// 줄바꿈: endl 쓰지 말고 "\n" (endl은 flush라 느림)
cout << "ans\n";

// 실수 출력 (소수점 자리)
#include <iomanip>
cout << fixed << setprecision(6) << 3.141592 << "\n";  // 3.141592

// printf 형식
printf("%d\n", n);       // int
printf("%lld\n", n);     // long long
printf("%.6f\n", d);     // double, 소수점 6자리
printf("%02d\n", m);     // 두 자리 0채우기 (07)
```

---

## 2. STL 자료구조
<a id="stl"></a>

### 2.1 vector (동적 배열)
```cpp
vector<int> v;
v.push_back(3);          // 끝에 추가 O(1) amortized
v.pop_back();            // 끝 제거 O(1)
v.size();                // 크기
v[i];                    // 접근 O(1)
v.clear();               // 전체 삭제
v.empty();               // 비었는지

// 초기화 방법들
vector<int> v1(n);                       // 크기 n, 0으로 초기화
vector<int> v2(n, 5);                    // 크기 n, 5로 초기화
vector<int> v3 = {1, 2, 3};              // 리스트 초기화
vector<vector<int>> v4(n, vector<int>(m, 0));  // 2차원 n×m 0초기화

// 2차원 vector 탐색 빠르게 하는 팁: & 로 참조
for(int i = 0; i < n; i++){
    vector<int>& row = a[i];   // 복사 피함
    for(int j = 0; j < m; j++) cout << row[j];
}
```
**시간복잡도:** 접근/끝삽입삭제 O(1), 중간삽입삭제 O(N)

### 2.2 map (균형이진트리, 정렬됨)
```cpp
map<string, int> mp;
mp["apple"] = 3;                // 할당/접근 O(log N)
mp.insert({"banana", 5});
mp.size();
mp.erase("apple");

// 키 존재 확인 (count 사용)
if(mp.count("apple")) { /* 있음 */ }

// 찾기
auto it = mp.find("apple");
if(it != mp.end()) cout << it->second;

// 순회 (키 오름차순)
for(auto &[k, v] : mp) cout << k << " : " << v << "\n";
```
**주의:** `mp[key]`로 접근하면 없는 키도 기본값(0)으로 **생성해버림**. 존재만 확인할 땐 `count()`나 `find()`.

### 2.3 unordered_map (해시, 빠르지만 정렬 안 됨)
```cpp
unordered_map<string, int> ump;
// 사용법은 map과 동일, 평균 O(1) 접근
```

### 2.4 set (중복 없는 정렬 집합)
```cpp
set<int> st;
st.insert(3);
st.insert(3);          // 중복 무시
st.count(3);           // 1 또는 0
st.erase(3);
// 정렬된 순서로 순회됨
for(int x : st) cout << x << " ";

// lower_bound, upper_bound 지원
auto it = st.lower_bound(3);   // 3 이상 첫 원소
```

### 2.5 multiset (중복 허용 정렬 집합)
```cpp
multiset<int> ms;
ms.insert(3); ms.insert(3);    // 둘 다 들어감
ms.count(3);                   // 2
ms.erase(ms.find(3));          // 하나만 삭제 (주의: erase(3)는 3 전부 삭제)
```

### 2.6 stack (LIFO)
```cpp
stack<int> stk;
stk.push(1);
stk.top();        // 맨 위 (삭제 X)
stk.pop();        // 맨 위 삭제
stk.size();
stk.empty();
```

### 2.7 queue (FIFO)
```cpp
queue<int> q;
q.push(1);
q.front();        // 맨 앞
q.back();         // 맨 뒤
q.pop();
q.size();
```

### 2.8 deque (양방향)
```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();
dq[i];            // 인덱스 접근 O(1)
```

### 2.9 priority_queue (힙)
```cpp
// 내림차순 (기본, 큰 값이 top)
priority_queue<int> pq1;

// 오름차순 (작은 값이 top) — 다익스트라용
priority_queue<int, vector<int>, greater<int>> pq2;

pq.push(3);
pq.top();         // 최댓값/최솟값
pq.pop();
pq.size();
pq.empty();
```
**시간복잡도:** push/pop O(log N), top O(1)

### 2.10 pair / tuple
```cpp
pair<int, int> p = {1, 2};
p.first; p.second;
p = make_pair(3, 4);

// pair 정렬: first 우선, 같으면 second
vector<pair<int,int>> v = {{3,2},{1,4},{1,2}};
sort(v.begin(), v.end());  // {1,2},{1,4},{3,2}

// tuple (3개 이상)
tuple<int, int, int> t = make_tuple(1, 2, 3);
get<0>(t); get<1>(t); get<2>(t);

// 구조화된 바인딩 (C++17) - 더 간편
auto [a, b] = p;
auto [x, y, z] = t;
```

---

## 3. STL 알고리즘 함수
<a id="algo"></a>

> 모두 `<algorithm>` 헤더 (bits/stdc++.h에 포함됨)

### 3.1 sort
```cpp
vector<int> v = {3, 1, 4, 1, 5};
sort(v.begin(), v.end());              // 오름차순
sort(v.begin(), v.end(), greater<int>());  // 내림차순

int arr[5] = {3, 1, 4, 1, 5};
sort(arr, arr + 5);                    // 배열은 주소
sort(arr, arr + 5, greater<int>());

// 부분 정렬
sort(v.begin(), v.begin() + 3);        // 앞 3개만 정렬

// stable_sort: 같은 값 순서 유지 (원래 순서 보존 필요 시)
stable_sort(v.begin(), v.end());
```
**시간복잡도:** O(N log N)

### 3.2 lower_bound / upper_bound (정렬된 배열에서만!)
```cpp
vector<int> v = {1, 2, 3, 3, 3, 4, 100};
// 정렬되어 있어야 함!

// lower_bound: 값 이상이 처음 나오는 위치
auto lo = lower_bound(v.begin(), v.end(), 3);  // 인덱스 2

// upper_bound: 값 초과가 처음 나오는 위치
auto hi = upper_bound(v.begin(), v.end(), 3);  // 인덱스 5

// 인덱스 구하기
int idx = lower_bound(v.begin(), v.end(), 3) - v.begin();  // 2

// 값 찾기
int val = *lower_bound(v.begin(), v.end(), 3);  // 3

// 특정 값 개수 = upper - lower
int cnt = upper_bound(v.begin(), v.end(), 3) - lower_bound(v.begin(), v.end(), 3);  // 3

// 존재 여부: lower_bound가 가리키는 값이 찾는 값과 같으면 존재
bool found = (*lower_bound(v.begin(), v.end(), x) == x);
```
**시간복잡도:** O(log N) (정렬되어 있어야)

### 3.3 unique (중복 제거, 정렬 후 사용)
```cpp
vector<int> v = {1, 1, 2, 3, 3, 4};
sort(v.begin(), v.end());              // 먼저 정렬 필수!
v.erase(unique(v.begin(), v.end()), v.end());  // {1,2,3,4}
```

### 3.4 accumulate (합계)
```cpp
vector<int> v = {1,2,3,4,5};
int sum = accumulate(v.begin(), v.end(), 0);        // 15
// long long 합은 세 번째 인자를 0LL로!
ll bigsum = accumulate(v.begin(), v.end(), 0LL);
```

### 3.5 max_element / min_element
```cpp
vector<int> v = {3, 1, 4, 1, 5};
auto it = max_element(v.begin(), v.end());
cout << *it << " at index " << (it - v.begin());  // 5 at index 4

int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());

// 배열
int arr[5] = {3,1,4,1,5};
int mx = *max_element(arr, arr + 5);
```

### 3.6 fill / memset (초기화)
```cpp
// fill: 모든 타입 가능 (권장)
int arr[100];
fill(arr, arr + 100, 0);                // 0으로 초기화
fill(arr, arr + 100, -1);               // -1도 가능
vector<int> v(100);
fill(v.begin(), v.end(), 0);

// 2차원 배열 fill
int a[10][10];
fill(&a[0][0], &a[0][0] + 10*10, 0);

// memset: 1바이트 단위, 0/-1/0x3f만 안전 (바이트 단위라 다른 값 위험)
memset(arr, 0, sizeof(arr));            // 0
memset(arr, -1, sizeof(arr));           // -1 (모든 비트 1)
memset(arr, 0x3f, sizeof(arr));         // 큰 값 (INF 대용)
```

### 3.7 reverse
```cpp
string s = "hello";
reverse(s.begin(), s.end());            // "olleh"

vector<int> v = {1,2,3};
reverse(v.begin(), v.end());            // {3,2,1}
```

### 3.8 find
```cpp
vector<int> v = {1,2,3,4};
auto it = find(v.begin(), v.end(), 3);
if(it != v.end()) cout << "found at " << (it - v.begin());

string s = "hello";
size_t pos = s.find("ll");              // 2, 없으면 string::npos
```

### 3.9 copy / memcpy
```cpp
int src[5] = {1,2,3,4,5}, dst[5];
copy(src, src+5, dst);                  // 안전한 복사
// memcpy도 가능하지만 주소 계산 주의
```

### 3.10 rotate (배열 회전)
```cpp
vector<int> v = {1,2,3,4,5,6};
rotate(v.begin(), v.begin()+1, v.end());   // {2,3,4,5,6,1} (왼쪽 1칸)
rotate(v.begin(), v.begin()+2, v.end());   // {3,4,5,6,1,2} (왼쪽 2칸)
// 오른쪽으로 1칸: begin()+(size-1)
rotate(v.begin(), v.begin()+(v.size()-1), v.end());  // 오른쪽 1칸
```

### 3.11 next_permutation / prev_permutation
```cpp
// 정렬 필수! (오름차순)
vector<int> v = {1,2,3};
sort(v.begin(), v.end());
do {
    for(int x : v) cout << x << " ";
    cout << "\n";
} while(next_permutation(v.begin(), v.end()));
```

### 3.12 __gcd / gcd
```cpp
int g = __gcd(12, 18);          // 6 (구버전)
int g = gcd(12, 18);            // 6 (C++17, <numeric>)
```

### 3.13 max / min / swap
```cpp
max(3, 5);                      // 5
max({1,2,3,4});                 // 4 (초기화 리스트)
min(3, 5);
swap(a, b);                     // 교환
```

---

## 4. 문자열 처리
<a id="string"></a>

### 4.1 string 기본
```cpp
string s = "hello";
s.size();                       // 5 (또는 s.length())
s[i];                           // i번째 문자
s += " world";                  // 이어붙이기
s.substr(0, 3);                 // "hel" (시작위치, 길이)
s.substr(2);                    // "llo" (시작위치부터 끝까지)
s.find("ll");                   // 2 (없으면 string::npos)
s.insert(2, "XX");              // "heXXllo"
s.erase(2, 2);                  // "hello" (위치, 개수)
s.pop_back();                   // 끝 한 글자 삭제
```

### 4.2 문자 ↔ 숫자 변환
```cpp
// 문자를 숫자로
char c = '5';
int n = c - '0';                // 5

// 숫자를 문자로
int n = 5;
char c = n + '0';               // '5'

// string → int
string s = "123";
int n = stoi(s);                // 123
long long ll = stoll(s);

// int → string
int n = 123;
string s = to_string(n);        // "123"

// C 스타일
int n = atoi("123");
char buf[10]; sprintf(buf, "%d", n);
```

### 4.3 아스키코드
```cpp
char c = 'A';
int asc = (int)c;               // 65
char c2 = 65;                   // 'A'

// 대문자 ↔ 소문자
char upper = toupper('a');      // 'A'
char lower = tolower('A');      // 'a'
// 또는 직접
if(c >= 'a' && c <= 'z') c -= 32;   // 소→대
if(c >= 'A' && c <= 'Z') c += 32;   // 대→소

// 문자가 숫자인지/알파벳인지
isdigit(c);                     // 숫자?
isalpha(c);                     // 알파벳?
isalnum(c);                     // 숫자 or 알파벳?
```

### 4.4 string 정렬/비교 주의
```cpp
// 문자열 비교: 사전순이 아닌 ASCII/길이 혼합 주의!
// "111" vs "33": 길이 비교 먼저 하지 않으면 "33" > "111" (ASCII 비교)
// 숫자 문자열 비교 시 길이 먼저 비교할 것
sort(v.begin(), v.end(), [](string a, string b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
});
```

### 4.5 문자열 분할 (split, 직접 구현)
```cpp
// STL에는 split이 없음. 직접 구현:
vector<string> split(string s, char delim) {
    vector<string> res;
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) res.push_back(item);
    return res;
}
// 사용: split("a,b,c", ',') → {"a","b","c"}
```

### 4.6 stringstream 활용
```cpp
// 문자열을 단어별로 자르기 (공백 기준)
string line = "hello world 123";
stringstream ss(line);
string word;
while(ss >> word) cout << word << "\n";

// 타입 변환
stringstream ss;
ss << 123;
string s = ss.str();            // "123"
```

### 4.7 한글 주의
한글은 UTF-8에서 한 글자 = 3바이트. `s[i]`로 한글 한 글자 단위 접근 불가.

---

## 5. 수학 / 정수론
<a id="math"></a>

### 5.1 최대공약수(GCD) / 최소공배수(LCM)
```cpp
// C++17: <numeric>의 gcd
int g = gcd(a, b);

// 직접 구현 (유클리드 호제법)
int gcd(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// 재귀 버전
int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }

// LCM
int lcm(int a, int b){ return a / gcd(a, b) * b; }  // 오버플로 주의: 나누기 먼저!
```

### 5.2 모듈러 연산 (MOD)
```cpp
const int MOD = 1e9 + 7;
// (a + b) % MOD
// (a - b + MOD) % MOD    ← 음수 방지! +MOD 필수
// (a * b) % MOD
// (a / b) % MOD → 페르마 소정리로 b^(MOD-2) 곱하기 (분할정복 거듭제곱)
```

### 5.3 거듭제곱 / 분할정복 거듭제곱 (모듈러)
```cpp
// 단순 거듭제곱 (long long 결과)
ll power(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret *= a;     // b가 홀수면 곱하기
        a *= a;
        b >>= 1;
    }
    return ret;
}

// 모듈러 거듭제곱 (MOD로 나머지)
ll powmod(ll a, ll b, ll mod){
    ll ret = 1;
    a %= mod;
    while(b){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

// 모듈러 역원 (페르마 소정리, MOD가 소수일 때)
ll modinv(ll a, ll mod){ return powmod(a, mod - 2, mod); }
```

### 5.4 소수 판별 (O(√N))
```cpp
bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; (ll)i*i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}
```

### 5.5 에라토스테네스의 체 (N 이하 소수 전부, O(N log log N))
```cpp
const int MAX = 1000001;
bool che[MAX];
vector<int> sieve(int max_n){
    vector<int> primes;
    for(int i = 2; i <= max_n; i++){
        if(che[i]) continue;
        for(int j = 2*i; j <= max_n; j += i) che[j] = true;
    }
    for(int i = 2; i <= max_n; i++) if(!che[i]) primes.push_back(i);
    return primes;
}
// 주의: MAX가 1000만 넘어가면 메모리 부족 → isPrime() 함수로 개별 판별
```

### 5.6 등차수열의 합
```cpp
// 1부터 n까지 합
ll sum1toN(ll n){ return n * (n + 1) / 2; }

// a부터 b까지 합 (a<=b)
ll sumAtoB(ll a, ll b){ return (a + b) * (b - a + 1) / 2; }
```

### 5.7 소인수분해
```cpp
vector<pair<int,int>> factorize(int n){
    vector<pair<int,int>> res;
    for(int i = 2; (ll)i*i <= n; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){ n /= i; cnt++; }
            res.push_back({i, cnt});
        }
    }
    if(n > 1) res.push_back({n, 1});
    return res;
}
```

### 5.8 조합 수학 (nCr)
```cpp
// 작은 n: 파스칼 삼각형 DP
ll comb[2001][2001];
void build(){
    for(int i = 0; i <= 2000; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    }
}

// 모듈러 nCr (큰 n, MOD 소수)
ll fact[MAX], inv[MAX];
fact[0] = 1;
for(int i = 1; i < MAX; i++) fact[i] = fact[i-1] * i % MOD;
inv[MAX-1] = modinv(fact[MAX-1], MOD);
for(int i = MAX-2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % MOD;
ll nCr(int n, int r){ return fact[n] * inv[r] % MOD * inv[n-r] % MOD; }
```

### 5.9 n진법 변환
```cpp
// 10진수 → k진법 문자열
string toBase(int n, int k){
    if(n == 0) return "0";
    string s;
    while(n){ s += to_string(n % k); n /= k; }
    reverse(s.begin(), s.end());
    return s;
}

// k진법 문자열 → 10진수
int toDec(string s, int k){
    int n = 0;
    for(char c : s) n = n * k + (c - '0');
    return n;
}
```

---

## 6. 순열 / 조합
<a id="perm"></a>

### 6.1 next_permutation (모든 순열)
```cpp
// 정렬 필수 (오름차순)!
vector<int> v = {1,2,3};
sort(v.begin(), v.end());
do {
    for(int x : v) cout << x << " ";
    cout << "\n";
} while(next_permutation(v.begin(), v.end()));
// prev_permutation은 내림차순에서 시작
```
**시간복잡도:** O(N! × N). N ≤ 10 정도만 가능.

### 6.2 재귀로 순열 만들기
```cpp
int n = 5;
int arr[5] = {1,2,3,4,5};
bool used[5];
vector<int> v;

void perm(int depth){
    if(v.size() == n){
        for(int x : v) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = true;
        v.push_back(arr[i]);
        perm(depth + 1);
        v.pop_back();
        used[i] = false;
    }
}
```

### 6.3 재귀로 조합 만들기 (n개 중 r개)
```cpp
int n = 5, k = 3;
int a[5] = {1,2,3,4,5};

void combi(int start, vector<int> &b){
    if(b.size() == k){
        for(int x : b) cout << x << " ";
        cout << "\n";
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}
// 호출: vector<int> b; combi(-1, b);
```

### 6.4 중첩 for문으로 조합 (r이 작고 고정일 때)
```cpp
// 5개 중 3개
for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
        for(int k = j+1; k < n; k++)
            cout << i << " " << j << " " << k << "\n";
```

---

## 7. 누적합 / 구간합
<a id="prefix"></a>

> "구간"에 대한 많은 "쿼리"가 나올 때, 그리고 요소가 **변하지 않는 정적**이면 누적합.

### 7.1 1차원 누적합
```cpp
int n; cin >> n;
vector<int> a(n), psum(n+1, 0);    // psum 크기 n+1!
for(int i = 0; i < n; i++){
    cin >> a[i];
    psum[i+1] = psum[i] + a[i];
}
// 구간 [l, r] (0-indexed, 닫구간)의 합
int l = 2, r = 5;
int sum = psum[r+1] - psum[l];
```

### 7.2 2차원 누적합
```cpp
int a[1001][1001], psum[1002][1002];
// 입력 후
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
    }
}
// (r1,c1) ~ (r2,c2) 직사각형 합
int sum = psum[r2][c2] - psum[r1-1][c2] - psum[r2][c1-1] + psum[r1-1][c1-1];
```

---

## 8. 완전탐색 & 백트래킹
<a id="brute"></a>

### 8.1 재귀로 모든 경우 탐색 (예: 부분집합의 합)
```cpp
int n = 5;
int a[5] = {1,2,3,4,5};

// idx번째 원소를 고르거나/고르지 않거나
void go(int idx, int sum){
    if(idx == n){
        cout << sum << "\n";
        return;
    }
    go(idx + 1, sum + a[idx]);     // 고른다
    go(idx + 1, sum);              // 고르지 않는다
}
```

### 8.2 백트래킹 (가지치기)
```cpp
// N개 중 합을 mod 11 했을 때 최댓값
int n, a[20];
int ans = 0;

void go(int idx, int sum){
    // 가지치기: 더 이상 최적이 될 수 없으면 return (생략 가능)
    if(idx == n){
        ans = max(ans, sum % 11);
        return;
    }
    go(idx + 1, sum + a[idx]);     // 고른다
    go(idx + 1, sum);              // 고르지 않는다
}
```

### 8.3 원복 (복구) 패턴
```cpp
// 상태를 바꾸고 → 재귀 → 원래대로 되돌림
void back(int here){
    // 기저
    for(int there : adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;        // 변경
        back(there);
        visited[there] = 0;        // 원복 ★
    }
}
```

### 8.4 비트마스크로 부분집합 순회
```cpp
int n = 5;
for(int mask = 0; mask < (1 << n); mask++){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)) sum += a[i];
    }
    // mask에 해당하는 부분집합의 합
}
```

---

## 9. 그래프 표현
<a id="graph"></a>

### 9.1 인접 리스트 (일반적, 희소 그래프)
```cpp
int n, m;
vector<int> adj[1001];        // 가중치 없음

// 간선 입력
for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);      // 무방향
}

// 가중치 있을 때
vector<pair<int,int>> adj2[1001];   // {to, weight}
adj2[u].push_back({v, w});
```

### 9.2 인접 행렬 (조밀 그래프, V 작을 때)
```cpp
int adj[101][101];            // 가중치 저장 (0=연결없음 또는 INF)
// V ≤ 400 정도일 때만
```

### 9.3 방향 벡터 (맵 탐색용)
```cpp
// 4방향 (상, 우, 하, 좌)
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 8방향 (대각선 포함)
const int dy8[] = {-1,-1,0,1,1,1,0,-1};
const int dx8[] = {0,1,1,1,0,-1,-1,-1};

// 사용
int y = 0, x = 0;
for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;  // 범위 체크 필수!
    if(a[ny][nx] == 0) continue;    // 갈 수 없는 곳
    if(visited[ny][nx]) continue;   // 이미 방문
    // ...
}
```

### 9.4 인접 리스트 vs 행렬
| 항목 | 인접 리스트 | 인접 행렬 |
|------|------------|-----------|
| 공간 | O(V+E) | O(V²) |
| 간선 존재 확인 | O(degree) | O(1) |
| 모든 간선 순회 | O(E) | O(V²) |
| 희소 그래프 | ✓ 권장 | |
| 조밀 그래프 | | ✓ 권장 |

---

## 10. DFS / BFS
<a id="dfs"></a>

### 10.1 DFS (인접 리스트) — 재귀
```cpp
vector<int> adj[1001];
bool visited[1001];

// 구현 1: 호출 전 방문 체크
void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(!visited[there]) dfs(there);
    }
}
// 호출: visited[1] = 1; dfs(1);  (또는 그냥 dfs(1))

// 구현 2: 진입 후 방문 체크 (깔끔)
void dfs(int here){
    if(visited[here]) return;
    visited[here] = 1;
    for(int there : adj[here]) dfs(there);
}
```

### 10.2 DFS (맵 탐색, 2D) — 완전 템플릿
```cpp
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int a[104][104];
bool visited[104][104];

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}
// 호출: dfs(0, 0);
```

### 10.3 연결된 컴포넌트 개수
```cpp
int cnt = 0;
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(a[i][j] == 1 && !visited[i][j]){
            cnt++;
            dfs(i, j);
        }
    }
}
cout << cnt;
```

### 10.4 BFS — 최단거리 (가중치 같은 그래프)
```cpp
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104];

int main(){
    int sy, sx, ey, ex;
    cin >> n >> m >> sy >> sx >> ey >> ex;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];
    
    queue<pair<int,int>> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});
    
    while(q.size()){
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;   // ★ 거리 저장
            q.push({ny, nx});
        }
    }
    cout << visited[ey][ex];
}
```
**핵심:** `visited[ny][nx] = visited[y][x] + 1` 이 부분이 최단거리 저장. `tie(y, x) = q.front()` 도 가능.

### 10.5 DFS vs BFS 선택
| 용도 | 선택 |
|------|------|
| 최단거리 (가중치 동일) | BFS |
| 모든 경로 탐색 / 백트래킹 | DFS |
| 연결요소 개수 | 둘 다 가능 |
| 위상정렬 | DFS |

---

## 11. 트리 순회
<a id="tree"></a>

### 11.1 이진트리 순회
```cpp
struct Node {
    int left, right;
};
Node tree[10001];

// 전위 순회 (Preorder): 루트 → 왼쪽 → 오른쪽
void preorder(int node){
    if(node == -1) return;
    cout << node << " ";
    preorder(tree[node].left);
    preorder(tree[node].right);
}

// 중위 순회 (Inorder): 왼쪽 → 루트 → 오른쪽
void inorder(int node){
    if(node == -1) return;
    inorder(tree[node].left);
    cout << node << " ";
    inorder(tree[node].right);
}

// 후위 순회 (Postorder): 왼쪽 → 오른쪽 → 루트
void postorder(int node){
    if(node == -1) return;
    postorder(tree[node].left);
    postorder(tree[node].right);
    cout << node << " ";
}
```

### 11.2 레벨 순회 (BFS)
```cpp
void levelorder(int root){
    queue<int> q;
    q.push(root);
    while(q.size()){
        int node = q.front(); q.pop();
        cout << node << " ";
        if(tree[node].left != -1) q.push(tree[node].left);
        if(tree[node].right != -1) q.push(tree[node].right);
    }
}
```

---

## 12. 정렬 응용 (struct, 비교, pq)
<a id="sort"></a>

### 12.1 compare 함수
```cpp
// 1순위 a 오름차순, 2순위 b 오름차순
struct Point { int y, x; };
bool cmp(const Point &u, const Point &v){
    if(u.y == v.y) return u.x < v.x;
    return u.y < v.y;
}
// 사용: sort(v.begin(), v.end(), cmp);
```

### 12.2 struct에 operator< 정의
```cpp
struct Point {
    int y, x, z;
    Point(int y, int x, int z) : y(y), x(x), z(z) {}
    Point() { y = -1; x = -1; z = -1; }
    
    // x 오름차순, 같으면 y 내림차순, 같으면 z 오름차순
    bool operator < (const Point &a) const {
        if(x == a.x){
            if(y == a.y) return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
};
// 사용: sort(v.begin(), v.end());   (compare 없이)
```

### 12.3 lambda 정렬
```cpp
vector<pair<int,int>> v;
sort(v.begin(), v.end(), [](const auto &a, const auto &b){
    return a.second < b.second;       // second 기준 오름차순
});
```

### 12.4 구조체를 담은 priority_queue
```cpp
struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
    Point() { y = -1; x = -1; }
    // 주의: pq는 반대로 설정해야 함! 작은 값이 top이려면 > 사용
    bool operator < (const Point &a) const {
        return x > a.x;       // x 작은 게 top (오름차순 pq)
    }
};
priority_queue<Point> pq;
```

---

## 13. 이분탐색
<a id="binary"></a>

> **정렬된 배열**에서 탐색 범위를 절반씩 줄이며, 조건을 만족하는 값 찾기.
> "최대/최소 ~한 값" 문제에서 결정 문제로 변환해서 쓰는 경우가 많음 (매개변수 탐색).

### 13.1 기본 이분탐색 (값 찾기)
```cpp
// 정렬된 배열에서 target 위치
int binarySearch(vector<int>& v, int target){
    int lo = 0, hi = v.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(v[mid] == target) return mid;
        else if(v[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
// 또는 그냥 binary_search, lower_bound 쓰기
bool found = binary_search(v.begin(), v.end(), target);
```

### 13.2 매개변수 탐색 템플릿 (가장 많이 쓰임)
```cpp
// "조건 check(x)를 만족하는 x의 최댓값/최솟값" 찾기
// check가 단조성을 가져야 함 (x 커질수록 true/false 한쪽으로만 감)

bool check(ll mid){
    // mid가 조건 만족하는지 검사
    return /* true/false */;
}

// 조건 만족하는 최댓값
ll lo = 0, hi = 1e18;
while(lo <= hi){
    ll mid = (lo + hi) / 2;
    if(check(mid)) lo = mid + 1;    // 만족 → 더 큰 값 도전
    else hi = mid - 1;
}
cout << hi;       // hi가 정답

// 조건 만족하는 최솟값
ll lo = 0, hi = 1e18;
while(lo <= hi){
    ll mid = (lo + hi) / 2;
    if(check(mid)) hi = mid - 1;    // 만족 → 더 작은 값 도전
    else lo = mid + 1;
}
cout << lo;       // lo가 정답
```

### 13.3 오버플로 주의
```cpp
// (lo + hi)가 long long 범위 넘을 수 있음
ll mid = lo + (hi - lo) / 2;    // 안전한 버전
```

---

## 14. 투포인터 / 슬라이딩 윈도우
<a id="twopointer"></a>

> 정렬된 배열에서 두 포인터로 쌍 찾기 / 연속 구간 문제.

### 14.1 투포인터 (정렬 후 양 끝에서)
```cpp
// 두 수의 합이 x인 쌍의 개수
int n, x; cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++) cin >> a[i];
cin >> x;
sort(a.begin(), a.end());

int cnt = 0, l = 0, r = n - 1;
while(l < r){
    if(a[l] + a[r] == x){ cnt++; r--; }
    else if(a[l] + a[r] > x) r--;
    else l++;
}
cout << cnt;
```

### 14.2 투포인터 (같은 방향, 구간 합)
```cpp
// 연속 부분합이 M이 되는 경우의 수
int lo = 0, sum = 0, cnt = 0;
for(int hi = 0; hi < n; hi++){
    sum += a[hi];
    while(sum > M && lo <= hi){
        sum -= a[lo];
        lo++;
    }
    if(sum == M) cnt++;
}
```

### 14.3 슬라이딩 윈도우 (고정 크기)
```cpp
// 크기 k인 윈도우의 최대 합
int sum = 0;
for(int i = 0; i < k; i++) sum += a[i];
int mx = sum;
for(int i = k; i < n; i++){
    sum += a[i] - a[i - k];       // 한 칸 밀기
    mx = max(mx, sum);
}
```

---

## 15. 그리디
<a id="greedy"></a>

> 매 순간 최적의 선택이 전체 최적이 되는 알고리즘. **정당성 증명이 중요.**
> 조건: (1) 최적 부분 구조 (2) 탐욕 선택 속성.

### 15.1 동전 거스름 (대표 예)
```cpp
// 큰 단위부터
int n = 1260;
int coins[] = {500, 100, 50, 10};
int cnt = 0;
for(int c : coins){
    cnt += n / c;
    n %= c;
}
cout << cnt;
```

### 15.2 회의실 배정 / 활동 선택 (끝나는 시간순 정렬)
```cpp
// 끝나는 시간 빠른 순으로 선택
vector<pair<int,int>> v;    // {end, start}
for(int i = 0; i < n; i++){
    int s, e; cin >> s >> e;
    v.push_back({e, s});
}
sort(v.begin(), v.end());

int cnt = 0, lastEnd = 0;
for(auto [end, start] : v){
    if(start >= lastEnd){
        cnt++;
        lastEnd = end;
    }
}
cout << cnt;
```

### 15.3 라인 스위핑 (겹치는 선분)
```cpp
// {위치, +1/-1}로 시작/끝 표시
vector<pair<int,int>> events;
for(int i = 0; i < n; i++){
    int s, e; cin >> s >> e;
    events.push_back({s, 1});
    events.push_back({e, -1});
}
sort(events.begin(), events.end());
int cur = 0, mx = 0;
for(auto [pos, delta] : events){
    cur += delta;
    mx = max(mx, cur);     // 최대 겹침
}
```

---

## 16. 동적계획법 DP
<a id="dp"></a>

> **DP = 완전탐색 + 메모이제이션.** 중복되는 부분문제를 한 번만 계산.
> 조건: (1) 최적 부분 구조 (2) 중복 부분문제.

### 16.1 DP 구조 (4단계)
```cpp
// 1. 초기화: -1로 (아직 계산 안 함 표시)
// 2. 기저사례 (Base Case): 가장 작은 값
// 3. 메모이제이션: 이미 계산했으면 반환
// 4. 로직: 점화식 계산
```

### 16.2 피보나치 - 탑다운 (재귀 + 메모)
```cpp
int dp[1004];
int fibo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    int &ret = dp[n];
    if(ret != -1) return ret;       // 메모이제이션
    return ret = fibo(n-1) + fibo(n-2);
}
int main(){
    memset(dp, -1, sizeof(dp));
    cout << fibo(10);
}
```

### 16.3 피보나치 - 바텀업 (반복문)
```cpp
int dp[1004];
int n = 10;
dp[0] = 0; dp[1] = 1;
for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
cout << dp[n];
// 바텀업이 일반적으로 더 빠름 (재귀 오버헤드 없음)
```

### 16.4 LIS (최장 증가 부분 수열) - O(N²)
```cpp
int n, a[1001], dp[1001], ret = 0;
for(int i = 0; i < n; i++){
    int maxValue = 0;
    for(int j = 0; j < i; j++){
        if(a[j] < a[i] && maxValue < dp[j]) maxValue = dp[j];
    }
    dp[i] = maxValue + 1;
    ret = max(ret, dp[i]);
}
cout << ret;
```

### 16.5 LIS - O(N log N)
```cpp
vector<int> lis;
for(int i = 0; i < n; i++){
    auto it = lower_bound(lis.begin(), lis.end(), a[i]);
    if(it == lis.end()) lis.push_back(a[i]);
    else *it = a[i];
}
cout << lis.size();
// 주의: lis의 원소가 실제 LIS는 아님 (길이만 정확)
```

### 16.6 LIS trace (경로 복원, O(N²))
```cpp
int a[1001], dp[1001], prev_idx[1001];
// dp 계산 시 prev_idx도 저장
for(int i = 0; i < n; i++){
    int maxValue = 0, prev = -1;
    for(int j = 0; j < i; j++){
        if(a[j] < a[i] && maxValue < dp[j]){
            maxValue = dp[j];
            prev = j;
        }
    }
    dp[i] = maxValue + 1;
    prev_idx[i] = prev;
}
// 최댓값 위치에서 역추적
int last = max_element(dp, dp+n) - dp;
vector<int> path;
while(last != -1){
    path.push_back(a[last]);
    last = prev_idx[last];
}
reverse(path.begin(), path.end());
```

### 16.7 LCS (최장 공통 부분 수열)
```cpp
string s1, s2;
int dp[1001][1001];
for(int i = 1; i <= s1.size(); i++){
    for(int j = 1; j <= s2.size(); j++){
        if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
cout << dp[s1.size()][s2.size()];
```

### 16.8 배낭 문제 (0/1 Knapsack)
```cpp
// 무게 합이 W 이하인 최대 가치
int n, W;
int w[101], val[101];
int dp[101][100001];      // dp[i][weight]
for(int i = 1; i <= n; i++){
    for(int j = 0; j <= W; j++){
        dp[i][j] = dp[i-1][j];     // i번째 안 담기
        if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + val[i]);
    }
}
cout << dp[n][W];
```

### 16.9 DP 템플릿 (탑다운 + 참조 메모이제이션)
```cpp
int dp[상태공간];
int f(int state){
    // 1. 기저사례
    if(state == base) return 초기값;
    // 2. 메모이제이션
    int &ret = dp[state];
    if(ret != -1) return ret;
    // 3. 로직
    ret = 초기값;
    for(각 선택) ret = max/min(ret, f(다음상태) + 비용);
    return ret;
}
// memset(dp, -1, sizeof(dp));
```

---

## 17. 최단경로
<a id="shortest"></a>

### 17.1 다익스트라 (양수 가중치, 단일 출발점)
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
const ll INF = 1e18;

vector<pl> adj[20001];    // {to, weight}
ll dist[20001];

void dijkstra(int start){
    priority_queue<pl, vector<pl>, greater<pl>> pq;  // {cost, node}, 오름차순
    fill(dist, dist + 20001, INF);
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto [here_cost, u] = pq.top(); pq.pop();
        if(dist[u] != here_cost) continue;   // 느긋한 삭제 ★
        for(auto &[v, weight] : adj[u]){
            ll new_cost = here_cost + weight;
            if(new_cost < dist[v]){
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}
```
**시간복잡도:** O((V+E) log V). **음수 가중치 불가.**

### 17.2 플로이드-워셜 (모든 쌍 최단경로)
```cpp
// V ≤ 400 정도일 때만. O(V³)
int dist[401][401];
int V, E;
// 초기화: dist[i][j] = INF, dist[i][i] = 0
// 입력: dist[u][v] = w

for(int k = 1; k <= V; k++){
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            if(dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
}
// dist[i][j]가 i→j 최단거리
```
**주의:** INF끼리 더하면 오버플로. `if(dist[i][k] != INF && dist[k][j] != INF)` 체크 또는 INF를 충분히 작게.

### 17.3 벨만-포드 (음수 가중치, 음수 사이클 감지)
```cpp
// "타임머신", "과거로", "블랙홀" 등 키워드 → 벨만포드 의심
const ll INF = 1e18;
struct Edge { int u, v, w; };
vector<Edge> edges;
ll dist[501];
int N, M;

bool bellmanFord(int start){
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;
    
    // N-1번 모든 간선 완화
    for(int i = 0; i < N - 1; i++){
        for(auto &e : edges){
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    // N번째에도 완화되면 음수 사이클 존재
    for(auto &e : edges){
        if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) return true;  // 음수 사이클
    }
    return false;
}
```
**시간복잡도:** O(VE)

### 17.4 최단경로 알고리즘 선택
| 알고리즘 | 가중치 | 용도 | 시간복잡도 |
|----------|--------|------|-----------|
| BFS | 모두 같음 | 가중치 동일 최단경로 | O(V+E) |
| 다익스트라 | 양수 | 단일 출발점 | O((V+E)logV) |
| 벨만-포드 | 음수 가능 | 음수 사이클 감지 | O(VE) |
| 플로이드-워셜 | 음수 가능 | 모든 쌍 | O(V³) |

---

## 18. 유니온파인드(서로소 집합)
<a id="uf"></a>

> 두 원소가 같은 집합인지 판별 / 집합 합치기. 경로압축 + rank로 거의 O(1).

### 18.1 기본 구현
```cpp
int p[100004];        // 부모
int uf_rank[100004];  // 트리 깊이

int find(int x){
    if(p[x] == x) return x;             // x가 루트
    return p[x] = find(p[x]);           // 경로압축 ★
}

void merge(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB) return;
    // rank 작은 쪽을 큰 쪽에 붙임
    if(uf_rank[rootA] < uf_rank[rootB]) p[rootA] = rootB;
    else {
        p[rootB] = rootA;
        if(uf_rank[rootA] == uf_rank[rootB]) uf_rank[rootA]++;
    }
}

// 초기화 (자기 자신이 부모)
for(int i = 0; i <= N; i++) p[i] = i;
// 또는 memset(p, -1, sizeof(p)) 로 하고 find 수정
```

### 18.2 -1 초기화 버전
```cpp
int p[100004];
int find(int x){
    if(p[x] == -1) return x;
    return p[x] = find(p[x]);
}
void merge(int a, int b){
    int rootA = find(a), rootB = find(b);
    if(rootA != rootB) p[rootA] = rootB;
}
// 초기화: memset(p, -1, sizeof(p));
```

### 18.3 같은 집합 판별
```cpp
if(find(x) == find(y)) cout << "YES\n";
else cout << "NO\n";
```

---

## 19. 비트마스킹
<a id="bit"></a>

### 19.1 기본 연산자
```cpp
int S = 0;
S |= (1 << idx);       // idx번째 비트 켜기
S &= ~(1 << idx);      // idx번째 비트 끄기
S ^= (1 << idx);       // idx번째 비트 토글
if(S & (1 << idx)) {}  // idx번째 비트 켜져있는지
int cnt = __builtin_popcount(S);   // 켜진 비트 개수
int lowest = (S & -S);             // 최하위 켜진 비트 (idx = log2(S&-S))
```

### 19.2 부분집합 순회
```cpp
// mask의 모든 부분집합 순회
for(int subset = mask; subset; subset = (subset - 1) & mask){
    // subset 처리
}
```

### 19.3 집합 연산
```cpp
A | B;        // 합집합
A & B;        // 교집합
A & ~B;       // 차집합 A - B
A ^ B;        // 대칭차
(1 << n) - 1; // 크기 n인 전체집합
```

### 19.4 비트마스킹 + DFS (외판원 순회 예시)
```cpp
// dp[here][visited]: here에 있고 visited 상태일 때 최소 비용
int n, W[16][16];
int dp[16][1 << 16];

int tsp(int here, int visited){
    if(visited == (1 << n) - 1){
        return W[here][0] ? W[here][0] : 1e9;
    }
    int &ret = dp[here][visited];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int next = 0; next < n; next++){
        if(visited & (1 << next)) continue;
        if(W[here][next] == 0) continue;
        ret = min(ret, tsp(next, visited | (1 << next)) + W[here][next]);
    }
    return ret;
}
// 호출: memset(dp, -1, sizeof(dp)); cout << tsp(0, 1);
```

---

## 20. 실전 팁 & 맞왜틀 체크리스트
<a id="tips"></a>

### 20.1 코딩테스트 팁
- **지역변수보다 전역변수**: 큰 배열은 전역으로 (스택 오버플로 방지 + 0 초기화)
- **배열 크기 여유있게**: N=100이면 `[104]` 정도로 (off-by-one 방지)
- **초기값은 답의 범위 밖에서**: 최댓값 구하면 `ret = 0`이 아닌 `ret = -1` 또는 매우 작은 값
- **1차원 배열 회전**: `rotate(v.begin(), v.begin()+k, v.end())` 로 왼쪽 k칸

### 20.2 2차원 배열 회전 (직접 구현)
```cpp
// 시계 방향 90도 (N×N)
void rotate90(int a[][104], int n){
    int temp[104][104];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp[j][n-1-i] = a[i][j];
    memcpy(a, temp, sizeof(temp));
}

// 2차원 대칭 (좌우)
for(int i = 0; i < n; i++)
    reverse(a[i], a[i] + m);
```

### 20.3 맞왜틀 체크리스트 (틀렸을 때 순서대로 확인)
1. **`bits/stdc++.h`에서 사용 불가능한 변수명**: `y1`, `next`, `prev`, `x1` 등 (백준에서 컴파일 에러)
   - 전역 변수명으로 `y1`, `_y1` 등 피하기
2. **입출력 싱크**: `ios_base::sync_with_stdio(false)` 켰으면 cin과 scanf 섞지 말 것
3. **스택 오버플로**: 큰 배열/깊은 재귀 → 전역 변수로 옮기기 (재귀 깊이 100만 넘으면 비재귀 고려)
4. **변수 초기화**: 전역/지역 초기화 안 된 값. 특히 TC(test case) 여러 개일 때 매번 clear
5. **실수형 정확도**: `double` 비교는 `abs(a-b) < 1e-9` 로 epsilon 사용
6. **문자열 크기**: `a[size]` 접근 시 out-of-range. 크기 N이면 `[N]`이 아닌 `[N+1]`
7. **참조 에러**: 빈 vector/queue에서 `front()`/`back()`/`top()` 호출
8. **UB(미정의 동작)**: 시프트 `1 << 31` (int 오버플로) → `1LL << 31`
9. **endl vs "\n"**: endl은 flush라 느림. 무조건 `"\n"`
10. **초기화 순서**: 전역 변수끼리 초기화 순서는 정의 순서가 아님 (의존성 주의)
11. **int 오버플로**: `int × int` → `long long` 캐스팅: `(ll)a * b`
12. **무한 루프**: while 조건문 오타, 증감 빠짐

### 20.4 컴파일 / 실행
```sh
g++ -std=c++17 -O2 -o sol sol.cpp
./sol < input.txt          # 파일로 입력
```

### 20.5 외워야 할 숫자
- `1e9` = 1,000,000,000 (int 범위 내)
- `1e18` ≈ `long long` 최댓값
- `INT_MAX` = 2,147,483,647 (`<climits>`)
- `LLONG_MAX` ≈ 9.2×10¹⁸
- `MOD = 1,000,000,007` (가장 흔한 모듈러)
- `1억` 번 연산 ≈ 1초

### 20.6 알고리즘 선택 가이드 (문제 유형별)
| 힌트 | 시도할 알고리즘 |
|------|----------------|
| 정렬 + 탐색 | 이분탐색, 투포인터 |
| "최소/최대" + 결정 | 매개변수 탐색(이분탐색) |
| 그래프 + 최단 | BFS(가중치동일) / 다익스트라 |
| "타임머신/과거" | 벨만-포드 (음수 사이클) |
| 모든 쌍 최단 | 플로이드-워셜 |
| "그룹/연결/친구" | 유니온파인드 |
| 겹치는 구간 | 라인 스위핑, 누적합 |
| 상태 작은 집합 | 비트마스킹 DP |
| "최장 증가" | LIS |
| "최장 공통" | LCS |
| N ≤ 20 | 완전탐색 / 비트마스크 |
| N ≤ 10 | 순열 (next_permutation) |
| 쿼리 많음 + 정적 | 누적합 |
| 쿼리 많음 + 동적 | 세그먼트 트리 (이 교안 범위 밖) |

---

## 🔧 자주 쓰는 스니펫 모음 (빠른 복붙)

### A. 기본 시작
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
```

### B. 그래프 입력 + DFS
```cpp
int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int here){
    visited[here] = true;
    for(int there : adj[here])
        if(!visited[there]) dfs(there);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // ...
}
```

### C. 2D BFS 최단거리 전체
```cpp
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int n, m, a[104][104], visited[104][104];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> a[i][j];
    
    queue<pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        auto [y, x] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!a[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n-1][m-1];
    return 0;
}
```

### D. 다익스트라 전체
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
int V, E, start;
vector<pll> adj[20001];
ll dist[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E >> start;
    for(int i = 0; i < E; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    fill(dist, dist + V + 1, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        auto [cost, u] = pq.top(); pq.pop();
        if(dist[u] != cost) continue;
        for(auto [v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
```

### E. 유니온파인드 전체
```cpp
#include <bits/stdc++.h>
using namespace std;
int p[1000001];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
void merge(int a, int b){
    a = find(a); b = find(b);
    if(a != b) p[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i++) p[i] = i;
    while(m--){
        int cmd, a, b; cin >> cmd >> a >> b;
        if(cmd == 0) merge(a, b);
        else cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
```

### F. DP (탑다운 템플릿)
```cpp
#include <bits/stdc++.h>
using namespace std;
int dp[상태공간];

int f(int state){
    // 기저
    if(state == 기저) return 기저값;
    // 메모
    int &ret = dp[state];
    if(ret != -1) return ret;
    // 로직
    ret = /* 점화식 */;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    // ...
    return 0;
}
```

---

## 📚 출처

본 참고서는 다음 교안의 내용을 정리한 것입니다:
- `알고리즘교안.pdf` (C++ 언어/STL, 214p)
- `알고리즘 개념교안.pdf` (알고리즘 개념, 214p)
- `알고리즘 문제해설.pdf` (문제 해설, 26p)

> 각 알고리즘의 자세한 원리/증명은 원본 PDF를 참조하세요.
