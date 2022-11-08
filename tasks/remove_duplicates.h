void removeDuplicates(vector<int>& array) {
    size_t insertIndex = 1;
    for(size_t i = 1; i < array.size(); ++i) {
        if(array[i - 1] != array[i]) {    
            array[insertIndex++] = array[i];
        }
    }
}