#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    typedef vector<int>::iterator iter;
    int n = 0;
    iter i = arr[n].begin();
    iter j = arr[n+1].begin()+1;
    iter k = arr[n+2].begin();
    
    vector<int> summation;
    //summation.reserve(16);
    
    while (1) {
        int top = *i + *(i+1) + *(i+2);
        int mid = *j;
        int bot = *k + *(k+1) + *(k+2);
        summation.push_back(top+mid+bot);
        
        if((i+2) != (arr[n].end()-1)) {
            i++;
            j++;
            k++;
        }
        else{
            ++n;
            if(n != (arr.size()-2)) {
                i = arr[n].begin();
                j = arr[n+1].begin()+1;
                k = arr[n+2].begin();
            }
            else {
                break;
            }
        }
        
    }
    
    return *max_element(summation.begin(), summation.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
