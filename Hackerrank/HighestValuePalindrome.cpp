string highestValuePalindrome(string s, int n, int k) {
    std::vector<int> unsatisfied_indexes;
    for(int i=0; i<n/2; ++i) {
        if(s[i] != s[n-i-1]) {
            unsatisfied_indexes.push_back(i);
        }
    }
    
    if(unsatisfied_indexes.size() > k) {
        return "-1";
    }
    
    // Apply minimum possible changes first
    // After this for loop is completed, the string 
    // will be palindrome
    for(int i=0; i<unsatisfied_indexes.size(); ++i) {
        int first_index = unsatisfied_indexes[i];
        int second_index = n-unsatisfied_indexes[i]-1;
        if(s[first_index] > s[second_index]) {
            s[second_index] = s[first_index];
        } else {
            s[first_index] = s[second_index];
        }
    }
    
    int changes_left = k-unsatisfied_indexes.size();
    
		// Starting from the highest digit, try to maximize the palindrome
    for(int i=0; i<s.size() && (changes_left > 0); ++i) {
        int first_index = i;
        int second_index = n-i-1;
        
        // if it is 9, don't touch it
        if(s[first_index] != '9') {
            auto iter = std::find(unsatisfied_indexes.begin(),
            unsatisfied_indexes.end(), i);
            // We have already decreased the change count by 1 if we
            // have visited this index before, so decrease it by 1
            if(iter != unsatisfied_indexes.end()) {
                --changes_left;
            } else { // We haven't visited this index we need to decrease it by 2
                if(changes_left < 2) {
                    break;
                }
                changes_left-=2;
            }
            
            // Now we can make the actual change
            s[first_index] = '9';
            s[second_index] = '9';
        }
    }
    
    // Edge case : Change middle element if it is not 9
    // and if we still have changes left
    if(k%2==1 && (changes_left >= 1) && (s[n/2] != '9')) {
        s[n/2] = '9';
        --changes_left;
    }
    
    return s;
}