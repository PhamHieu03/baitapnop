#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm kiểm tra một số có phải là số nguyên tố Blum hay không
bool isBlumPrime(int p) {
    return p % 4 == 3; // Kiểm tra điều kiện p ≡ 3 (mod 4)
}

// Hàm kiểm tra một số có phải là số nguyên tố hay không
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tạo ra các số Blum nhỏ hơn N
vector<int> generateBlumNumbers(int N) {
    vector<int> primes;
    vector<int> blumNumbers;

    // Tìm các số nguyên tố p ≡ 3 (mod 4)
    for (int i = 2; i < N; i++) {
        if (isPrime(i) && isBlumPrime(i)) {
            primes.push_back(i);
        }
    }

    // Tạo các số Blum từ các số nguyên tố vừa tìm được
    for (size_t i = 0; i < primes.size(); i++) {
        for (size_t j = i + 1; j < primes.size(); j++) {
            int blumNumber = primes[i] * primes[j];
            if (blumNumber < N) {
                blumNumbers.push_back(blumNumber);
            }
        }
    }

    // Sắp xếp danh sách các số Blum
    sort(blumNumbers.begin(), blumNumbers.end());

    return blumNumbers;
}

// Hàm kiểm tra một số có phải là số Blum hay không
bool isBlum(int num, const vector<int>& blumNumbers) {
    return binary_search(blumNumbers.begin(), blumNumbers.end(), num);
}

// Hàm tìm tất cả các cặp số Blum có tổng là số Blum nhỏ hơn N
void findBlumPairs(const vector<int>& blumNumbers, int N) {
    cout << "Các cặp số Blum có tổng là số Blum nhỏ hơn " << N << ":\n";
    for (size_t i = 0; i < blumNumbers.size(); i++) {
        for (size_t j = i + 1; j < blumNumbers.size(); j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (sum < N && isBlum(sum, blumNumbers)) {
                cout << blumNumbers[i] << " + " << blumNumbers[j] << " = " << sum << endl;
            }
        }
    }
}

// Hàm kiểm tra xem một số Blum M có tồn tại trong dãy số Blum đã tạo hay không
void checkBlumNumber(int M, const vector<int>& blumNumbers) {
    if (isBlum(M, blumNumbers)) {
        cout << M << " là một số Blum.\n";
    }
    else {
        cout << M << " không phải là một số Blum.\n";
    }
}

int main() {
    int N, M;

    cout << "Nhập N: ";
    cin >> N;

    // Tạo danh sách số Blum nhỏ hơn N
    vector<int> blumNumbers = generateBlumNumbers(N);

    cout << "Danh sách các số Blum nhỏ hơn " << N << ":\n";
    for (int num : blumNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Tìm các cặp số Blum có tổng là số Blum nhỏ hơn N
    findBlumPairs(blumNumbers, N);

    // Kiểm tra số Blum M
    cout << "\nNhập số Blum M cần kiểm tra: ";
    cin >> M;
    checkBlumNumber(M, blumNumbers);

    return 0;
}
