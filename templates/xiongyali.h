#include<cstring>
using namespace std;
const int maxn=203;

struct jiedian
{
  int n,dao[maxn];
};
		
int n,m,zuo[maxn],i,j,duiz[maxn],duiy[maxn],nn,t,rr=0;
jiedian dian[maxn];
bool yong[maxn];
/*zuo 左点的编号,一般是1-n吧 duiz,duiy分别是两边的匹配,
rr为最大匹配,dian记录左点的连接信息 */
bool xiong(int x)
{
  int i,tt;
//进入的点都是左点
  for (i=1;i<=dian[x].n;i++)//遍历所连所有右点
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))//未重复出现且没有和此点匹配（保证交替1
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(duiy[tt]))//如果是未匹配点，可作为终点，否则顺着它匹配的左点找增广轨（保证交替2），如果找到：
      {
        duiz[x]=tt;
        duiy[tt]=x;//连接左右，右与原匹配的边自动删除
        return true;
      }
    }
  }
  return false;
}

int main()
{
  for (i=1;i<=nn;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t))//找到增广轨
        rr++;//匹配数+1
    }
  }
  ouf<<rr<<endl;
}
