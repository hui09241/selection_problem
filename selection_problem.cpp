#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include <time.h>
using namespace std;
int main()
{
    int k,num,count1=100,inifi=9999;//quescount=0<-絋﹚琌100//count1癘羆碭计
    int q,j1=0,check_n=0;//癘材碭vector
    vector<int> ques_num;
    vector<int> classifi_num[20];
    vector<int> middle;
    vector<int> big_equal_small[3];
    vector<int> check;
    srand(time(NULL));
    for(int i=0; i<100; i++) //100睹计
        ques_num.push_back((rand()%1000)+1);//quescount++;
    cin>>k;//cout<<k;
    num=k;
    while(1)
    {
        if(ques_num.size()>5)
        {
            q=0,j1=0;//count1=100
            for(int i=0; i<ques_num.size(); i++) //だ舱//count1
            {
                if(j1==5)
                {
                    q++;
                    j1=0;
                }
                classifi_num[q].push_back(ques_num[i]);
                j1++;
            }
            if(ques_num.size()%5!=0)
            {
                for(int i=j1;i<5;i++)
                    classifi_num[q].push_back(inifi);
            }
            ques_num.clear();
            for(int i=0; i<=q; i++)
                sort(classifi_num[i].begin(),classifi_num[i].end());
            for(int i=0; i<=q; i++)
                middle.push_back(classifi_num[i][classifi_num[i].size()/2]);
            sort(middle.begin(),middle.end());
            if(middle.size()%2==0)//璝ㄤmiddle案计い丁ㄢ计ぇい计
                check_n=(middle[middle.size()/2-1]+middle[middle.size()/2])/2;
           else
            check_n=middle[middle.size()/2];
            if(check_n>1000)//い计1000玥┕玡计
                check_n=middle[middle.size()/2-1];
            middle.clear();
            cout<<"P:"<<check_n<<" ";//P
            for(int i=0; i<=q; i++)
            {
                for(int j=0; j<classifi_num[i].size(); j++)
                {
                    if (classifi_num[i][j]==9999)
                        break;
                    else if(check_n<classifi_num[i][j])
                        big_equal_small[0].push_back(classifi_num[i][j]);//big
                    else if (check_n==classifi_num[i][j])
                        big_equal_small[1].push_back(classifi_num[i][j]);//equal
                    else if (check_n>classifi_num[i][j])
                        big_equal_small[2].push_back(classifi_num[i][j]);//small
                }
            }
            for(int i=0; i<=q; i++)
                classifi_num[i].clear();
            if (1<=k&&k<=big_equal_small[0].size())//ex.k=33 ,程材材33
            {
                cout<<"搭计秖:"<<big_equal_small[1].size()+big_equal_small[2].size()<<endl;
                for(int i=0; i<big_equal_small[0].size(); i++)
                    ques_num.push_back(big_equal_small[0][i]);

            }
            else if(big_equal_small[0].size()<k&&k<=big_equal_small[0].size()+big_equal_small[1].size())//ボP碞琌璶т
            {
                cout<<"搭计秖:"<<big_equal_small[0].size()+big_equal_small[2].size()<<endl;
                cout<<"材"<<num<<"计:"<<check_n<<endl;
                break;
            }
            else
            {
                cout<<"搭计秖:"<<big_equal_small[0].size()+big_equal_small[1].size()<<endl;
                for(int i=0; i<big_equal_small[2].size(); i++)
                    ques_num.push_back(big_equal_small[2][i]);
                k=k-(big_equal_small[0].size()+big_equal_small[1].size());
            }
            big_equal_small[0].clear();
            big_equal_small[1].clear();
            big_equal_small[2].clear();

        }
        else
        {
            sort(ques_num.begin(),ques_num.end());
            reverse(ques_num.begin(),ques_num.end());
            cout<<"材"<<num<<"计:"<<ques_num[k-1]<<endl;
            break;
        }
    }

}
