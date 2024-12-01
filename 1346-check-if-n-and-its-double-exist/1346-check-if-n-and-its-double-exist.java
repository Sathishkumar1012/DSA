class Solution {
    public boolean checkIfExist(int[] arr) {
        HashSet<Integer>hs=new HashSet<>();
        
        for(int p:arr) {
            if((hs.contains(p/2) && p%2==0)  || hs.contains(p*2))
                return true;
            hs.add(p);
        }
        
        return false;
    }
}