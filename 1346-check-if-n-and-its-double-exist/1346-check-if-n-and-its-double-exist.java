class Solution {
    public boolean checkIfExist(int[] arr) {
        HashSet<Float>hs=new HashSet<>();
        
        for(int p:arr) {
            if(hs.contains(p/2.0f)  || hs.contains(p*2.0f))
                return true;
            hs.add((float)p);
        }
        
        return false;
    }
}