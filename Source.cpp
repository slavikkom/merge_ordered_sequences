#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int number, mumber;
    std::cin >> number >> mumber;
    std::vector<int> vect;
    for (int ii = 0; ii < number; ++ii) {
        for (int jj = 0; jj < mumber; ++jj) {
            int ar;
            std::cin >> ar;
            vect.push_back(ar);
        }
    }
    int kk = 1;
    while (kk < number) {
        int ll = 0;
        for (int ii = 0; (ii + 2) * kk <= number; ii += 2) {
            ll = ii;
            std::inplace_merge(vect.begin() + ii * kk * mumber,
                vect.begin() + (ii + 1)* kk * mumber, vect.begin() + (ii + 2) * kk * mumber);
        }
        if (vect.size() > (ll + 2) * kk * mumber) {
            std::inplace_merge(vect.begin() + ll * kk * mumber,
                vect.begin() + (ll + 2) * kk * mumber, vect.end());
        }
        kk *= 2;
    }
    for (int ii = 0; ii < number * mumber; ++ii) {
        std::cout << vect[ii] << " ";
    }
    return 0;
};
