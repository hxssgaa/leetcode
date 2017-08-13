int candy(vector<int>& ratings) {
    if (ratings.size() == 0) return 0;
    if (ratings.size() == 1) return 1;
    int i = 0;
    int sum = 0;
    int before = 1;
    while (i < ratings.size()-1) {
        if (ratings[i+1]>ratings[i]) {
            sum += before;
            before++;
            i++;
        } else if (ratings[i+1]==ratings[i]) {
            sum += before;
            before = 1;
            i++;
        } else {
            int cur = i;
            while (ratings[cur+1]<ratings[cur]&&cur<ratings.size()-1)
                cur++;
            sum += (2+cur-i)*(cur-i-1)/2 + max(before, cur-i+1);
            i = cur;
            before = 1;
        }
    }
    sum += before;
    return sum;
}

//this is a better understanding solution.
 int candy(vector<int> &ratings)
 {
     int size=ratings.size();
     if(size<=1)
         return size;
     vector<int> num(size,1);
     for (int i = 1; i < size; i++)
     {
         if(ratings[i]>ratings[i-1])
             num[i]=num[i-1]+1;
     }
     for (int i= size-1; i>0 ; i--)
     {
         if(ratings[i-1]>ratings[i])
             num[i-1]=max(num[i]+1,num[i-1]);
     }
     int result=0;
     for (int i = 0; i < size; i++)
     {
         result+=num[i];
        // cout<<num[i]<<" ";
     }
     return result;
 }