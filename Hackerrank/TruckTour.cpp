int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size();
    int petrolRemain = 0;
    int state = 0;
    
    for (int i=0; i<n; i++){
        int petrol = petrolpumps[i][0];     // get petrol value from matrix
        int distance = petrolpumps[i][1];   // get distance value from matrix
        petrolRemain += petrol - distance;
        
        // check if remaining petrol is empty, reset the counter, and start from the next pumpstation
        if (petrolRemain < 0){
            state = i+1;
            petrolRemain = 0;
        }
    }
return state;
}