int sansaXor(vector<int> arr){

    int res = 0;
    if (arr.size() % 2 == 0) {
        return res;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            res ^= arr[i];
        }
    }

    return res;

}