class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m=version1.length();
        int n=version2.length();
        
        stringstream s(version1);
        stringstream t(version2);
        string a,b;
        
        int k,l;
        k=l=0;
        while(getline(s,a,'.') && getline(t,b,'.')) {
            int i,j;
            i=0;
            k+=a.length()+1;
            l+=b.length()+1;
            while(i<a.length() && a[i]=='0') {
                i++;
            }
            
            j=0;
            while(j<b.length() && b[j]=='0') {
                j++;
            }
            //cout<<a[i]<<"--"<<b[j]<<endl;
            int b1,b2;
            b1=a.length()-i;
            b2=b.length()-j;
            
            if(b1>b2 && a[i]!='0')
                return 1;
            else if(b2>b1 && b[j]!='0')
                return -1;
            
            while(i<a.length() && j<b.length()) {
                //cout<<a[i]<<"--"<<b[j]<<endl;
                if(a[i]>b[j])
                    return 1;
                else if(b[j]>a[i])
                    return -1;
                i++;
                j++;
            }
            
            //cout<<i<<"--"<<j<<endl;
            if(i<a.length())
                return 1;
            else if(j<b.length())
                return -1;
        }
        
        /*k-=1;
        l-=1;*/
        
        while(k<version1.length() && (version1[k]=='0' || version1[k]=='.')) {
            k++;
        }
        
        while(l<version2.length() && (version2[l]=='0' || version2[l]=='.')) {
            l++;
        }
        
        if(k<version1.length() && version1[k]!='0')
            return 1;
        else if(l<version2.length() && version2[l]!='0')
            return -1;
        else return 0;
    }
};