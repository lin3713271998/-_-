/*1707004540��־��*/
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define M  20 
#define FIN 5000 

//ͼ�ڽӾ��� 
typedef struct{
	char vexs[M];
	int edges[M][M];
	int n,e;//n:������e:���� 
}Mgraph;

//prim�㷨 
typedef struct edgedata{
	int beg,en;//�߶������ 
	int length;	
}edge; 
edge tree[M-1];	

//���������ڽӱ� 
typedef struct node{
int adjvex;
struct node *next;		
}edgenode; 
typedef struct de{
edgenode *firstedge;
char vertex;
}vertexnode;
typedef struct{
 vertexnode adjlist[M];
 int n,e;	
}aovgraph;

//���·�� 
typedef int dist[M][M];
typedef int path[M][M];


//ͼ���ڽӾ�����
void creat(Mgraph *g,char *s,int c){//c��ʾͼ�����ͣ�c=0��ʾ����ͼ 
int i,j,k,w;
FILE *rf;
rf = fopen(s,"r");	//fopen����ʹ�÷�����https://baike.baidu.com/item/fopen/10942321?fr=aladdin 
if(rf)
{
	fscanf(rf,"%d%d",&g->n,&g->e);
	for(i=0;i<g->n;i++)
	fscanf(rf,"%ls",&g->vexs[i]);
	
	for(i=0;i<g->n;i++)//��ʼ���ڽӾ��� 
	    for(j=0;j<g->n;j++)
	       if(i==j) {g->edges[i][j]=0;
		   }
		   else {g->edges[i][j]=FIN;
		   }
	   
	for(k=0;k<g->e;k++)//����� 
	{   fscanf(rf,"%d%d%d",&i,&j,&w);
		g->edges[i][j]=w;
	
		if(c==0) g->edges[j][i]=w; }   	
    fclose(rf);	 }	
	else g->n=0; 
}
//ͼ���ڽӱ���
void creatgraph(aovgraph *g2, char *s3, int c){
    int i, j, k; //ѭ������
    edgenode *s, *s2; //�����ýڵ�
    FILE *fp;
    fp = fopen(s3,"r");
    fscanf(fp, "%d %d", &g2->n, &g2->e); // n������, e����

    //¼�����Ϣ
    for(i = 0;i < g2->n; i++){
        fscanf(fp, "%1s", &g2->adjlist[i].vertex); //%1s�൱��%c//666 
        g2->adjlist[i].firstedge = NULL; //�߱���Ϊ��
    }

    //¼�����Ϣ
    for(k=0; k<g2->e; k++){
        fscanf(fp, "%d %d", &i, &j);
        s = (edgenode *)malloc(sizeof(edgenode)); //����ڵ���ʽ�ռ�
        s->adjvex = j;
        s->next = g2->adjlist[i].firstedge;
        g2->adjlist[i].firstedge = s;

        if(c == 0){ //��Ϊ������ͼ ������Ҫ������������
//             s = (edgenode *)malloc(sizeof(edgenode));   
//             s->adjvex = i; //�պ��������i j������
//             s->next = g->adjlist[j].firstedge;
//             g->adjlist[i].firstedge = s;      
            s2 = (edgenode*)malloc(sizeof(edgenode));
            s2->adjvex = i;
            s2->next = g2->adjlist[j].firstedge;
            g2->adjlist[j].firstedge = s2;
        }
    }		
} 

//Prim��С������ 
void prim(Mgraph g,edge tree[M-1]){
 edge x;
 int d,min,j,k,s,v;
 for(v=1;v<=g.n-1;v++)
 {
 	tree[v-1].beg=0;
	tree[v-1].en=v;
	tree[v-1].length=g.edges[0][v]; 
	}	
 for(k=0;k<g.n-3;k++)
 {
 	min = tree[k].length;
	for(j=k+1;j<g.n-2;j++)
	  if(tree[j].length<min)
	   {
	   	min = tree[j].length;
	   	s=j;
		} 
 	v=tree[s].en;
 	for(j=k+1;j<g.n-2;j++)
 	{d=g.edges[v][tree[j].en];
 	 if(d<tree[j].length)
 	   {tree[j].length=d;
 	    tree[j].beg=v;
		}
	 }
}	
printf("\n%c--%c %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
printf("the root of it is %c\n",g.vexs[0]);		
}



/* �ڽӾ���洢 - ��Դ���·�㷨 */ 
int floyd(Mgraph g,dist d, path p ) 
{     int i, j, k;     /* ��ʼ�� */ 
      
   for ( i=0; i<g.n; i++ )     
    for( j=0; j<g.n; j++ ) {      
	       d[i][j] = g.edges[i][j];          
		   p[i][j] = -1;         }    
	for( k=0; k<g.n; k++ )    
	for( i=0; i<g.n; i++ )     
	for( j=0; j<g.n; j++ )    
        if( d[i][k] + d[k][j] < d[i][j] ) {   
			d[i][j] = d[i][k] + d[k][j];    
			if ( i==j && d[i][j]<0 ) /* �����ָ�ֵȦ */                       
			  return false; /* ������ȷ��������ش����� */                 
			      p[i][j] = k;         }   
         return true; /* �㷨ִ����ϣ�������ȷ��� */ 
  }
 //���·���������
 void print(Mgraph g,dist d, path p ){
 	int i,j;
 	for(i=0;i<g.n;i++)
 	{for(j=0;j<g.n;j++)
 	 printf("%d--%d\n",p[i][j],d[i][j]);
	 }
 	
 	
 } 
 //���������������
void print2(aovgraph g2, int TopOrder[],int cnt)
{
    int i;
	for(i=0;i<=cnt;i++)
	printf("%d ",TopOrder[i]);
 }	   

/* �ڽӱ�洢 - ���������㷨 */ 
int topsort( aovgraph g2,int TopOrder[]) 
{    
    int Indegree[M], cnt,i;   
    int V,front,rear;
	   
	edgenode *W;    
    int queue[M];	     //  Queue Q = CreateQueue( Graph->Nv ); 
    front=rear=0;     
	      
	   for (V=0; V<g2.n; V++)  /* ��ʼ��Indegree[] */          
	   Indegree[V] = 0;             
	     
	   for (V=0; V<g2.n; V++)    /* ����ͼ���õ�Indegree[] */         
	   for (W=g2.adjlist[V].firstedge; W; W=W->next)             
	   Indegree[W->adjvex]++; /* �������<V, W->AdjV>�ۼ��յ����� */                  
	    
	   for (V=0; V<g2.n; V++)         
	   if ( Indegree[V]==0 )     /* ���������Ϊ0�Ķ������� */            
	   queue[rear ++]=V;                   
	   cnt = 0;      
	   while(front<rear){     //�����в�Ϊ��    
	  // V = DeleteQ(Q);
	  V=queue[front++]; 
	//  printf("%d",V);/* ����һ�����Ϊ0�Ķ��� */        
	   TopOrder[cnt++] = V; /* ��֮��Ϊ������е���һ��Ԫ�� */         
	          
	
	    for (W=g2.adjlist[V].firstedge; W; W=W->next)            
	   if ( --Indegree[W->adjvex] == 0 )/* ��ɾ��Vʹ��W->AdjV���Ϊ0 */                 
	   queue[rear++]=W->adjvex; // AddQ(Q, W->AdjV); /* ��ö������� */     
	    } /* while����*/   
		       
	   if ( cnt !=g2.n ) {
	   	printf("�л�·ERROR!");
	   	return false; /* ˵��ͼ���л�·, ���ز��ɹ���־ */   
	   }        
	   else   {
	   	       print2(g2,TopOrder,cnt);
				return true;
	   }      
	   
	   
}	   


/*������*/ 
int main(){
Mgraph g;
aovgraph g2;
int cnt;
int TopOrder[M];
char filename[30];
path p;
dist d;
 
printf("Please input you want to open the file name:\n");
gets(filename);

printf("����ͼ\n");
creat(&g,filename,0);
creatgraph(&g2,filename,0);
printf("��С������\n");
prim(g,tree);

printf("���·��(-1����ԭ�㣬5000���������)\n");
floyd(g,p,d); 
print(g,p,d);

printf("��������\n");
topsort(g2,TopOrder);


return 0;		
}






