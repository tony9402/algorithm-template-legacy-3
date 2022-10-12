//title: KMP
//prefix: kmp, KMP
//description: KMP O(|S| + |T|)
template<typename T> struct KMP {
    vector<int> fail;
    vector<int> failure(const T &Q) {
        fail.resize((int)S.size() + 1);
        for(int i = 1, j = 0; i < (int)Q.size(); ++i) {
            while(j > 0 && Q[i] != Q[j]) j = fail[j - 1];
            if(Q[i] == Q[j]) fail[i] ++j;
        }
        return fail;
    }
    vector<int> kmp(const T& P, const T& Q) {
        vector<int> res;
        for(int i = 0, j = 0; i < (int)a.size(); ++i) {
            while(j > 0 && P[i] != Q[j]) j = fail[j - 1];
            if(P[i] == Q[j]) {
                if(j + 1 == (int)Q.size()) res.push_back(i - (int)Q.size() + 1), j = fail[j - 1];
                else ++j;
            }
        }
        return res;
    }
};