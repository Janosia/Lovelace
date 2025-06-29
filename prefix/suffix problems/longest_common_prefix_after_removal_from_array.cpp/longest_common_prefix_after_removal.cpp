#include <iostream>
#include <vector>
#include <string>

int common(string &W1, string &W2){
    int len = min(W1.size(), W2.size());
    int i = 0;
    while(i<len  && W1[i] == W2[i]) i++;

    return i;
}

vector<int> main (vector<string>&words){
    int n = words.size();
    if( n == 1) return {0};

    vector<int>out(n, 0), prefix(n), suffix(n);
    prefix[0] =0, suffix[n-1] =0;
    for (int i =1; i<n; i++){
        prefix[i] = common(words[i-1], words[i]);
        prefix[i] = max(prefix[i-1], prefix[i]);
    }

    for (int i =n-2; i>=0; i--){
        suffix[i] = common(words[i+1], words[i]);
        suffix[i] = max(suffix[i+1], suffix[i]);
    }

    out[0] = max(prefix[0], suffix[1]); 
    out[n-1] = max(suffix[n-1], prefix[n-2]);

    for(int i =1; i<n-1; i++){
        out[i] = common(words[i-1], words[i+1]);
        out[i] = max(out[i], prefix[i-1]);
        out[i] = max(out[i], suffix[i+1])
    }
    return out;
}