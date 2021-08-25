// A C++ program to demonstrate operations of KD tree 
//#include<bits/stdc++.h> 
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include<map>
#include <math.h>
#include"mergesort.h"
using namespace std; 

const int k = 2; 
const float Inf = 99999999;
//fstream fin("dataset3.in");
//long int n = 1000000;
//fin >> n;
float pointsss[1000000][4]={};

// A structure to represent node of kd tree 
struct Node 
{ 
	float point[2]; // To store k dimensional point 
	struct Node *left, *right , *parent; 
    float num;
    bool dim;
    bool deleted = 0;
    int state;
    int city;
}; 
//struct Node* root ;
//root->left = NULL;
//root->right = NULL;
struct Node* newNode() 
{ 
  // Allocate memory for new node  
  struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
 
  // Initialize left and right children as NULL 
  node->left = NULL; 
  node->right = NULL; 
  node->deleted = 0;
  node->point[0] = Inf;
  node->point[1] = Inf;
  return(node); 
}

Node* root = newNode();
int size = 0;
void tree(Node *root, float points[][4], long int n,bool dim)
{
    //cout<<points[0][1]<<endl;
    //printArray(points, n);   
    //printArray(points, n);
    //cout<<"here"<<endl;
    mergeSort(points,0 , n-1, dim);
    //printArray(points, n);
    int i;
    int index;
    root->dim = dim;
    if (n%2 == 1)
    {
        //cout<<"yo"<<endl;
        index = n/2;
        
        root->num = points[index][root->dim];
        
        
    }
    else
    {
        //cout<<"arr"<<endl;
        index = n / 2;
        
        root->num = (points[index][root->dim] + points[index-1][root->dim]) / 2;
        //cout<<root->dim<<" and "<<index<<root->num<<endl;
        
    }
    
    
    
    
    if (n==1)
    {
        //cout<<"n = 1 "<<endl;
        root->point[0] = points[0][0];
        root->point[1] = points[0][1];
        root->city = points[0][2];
        root->state = points[0][3];
        //cout<<"we have\n";
        //cout<<points[0][0]<<","<<points[0][1]<<endl;
        //cout<<"size of output is "<<size<<endl;
        //cout<<"me and"<<endl;
        
        
        //printArray(output , 7);
        size+=1;
        //cout<<points[0][0]<<","<<points[0][1]<<endl;
        //cout<<"size of output is "<<size<<endl;
    }
    else if(n==2)
    {
        //cout<<"n = 2 "<<endl;
        float left[1][4]={};
        float right[1][4]={};
        if(points[0][root->dim] > points[1][root->dim])
        {
            //cout<<"here "<<endl;
            left[0][0]=points[1][0];
            left[0][1]=points[1][1];
            left[0][2]=points[1][2];
            left[0][3]=points[1][3];

            right[0][0]=points[0][0];
            right[0][1]=points[0][1];
            right[0][2]=points[0][2];
            right[0][3]=points[0][3];
        }
        else if(points[0][root->dim] < points[1][root->dim])
        {
            //cout<<"not here"<<endl;
            right[0][0]=points[1][0];
            right[0][1]=points[1][1];
            right[0][2]=points[1][2];
            right[0][3]=points[1][3];

            left[0][0]=points[0][0];
            left[0][1]=points[0][1];
            left[0][2]=points[0][2];
            left[0][3]=points[0][3];
        }
        else
        {
            root->right = newNode();
            root->right->parent = root;
            root->right->num = points[0][root->dim];
            if (dim==0)
                dim = 1;
            else
                dim = 0;
            root->right->dim = dim;
            root = root->right;
            if(points[0][root->dim] > points[1][root->dim])
            {
                //cout<<"here "<<endl;
                left[0][0]=points[1][0];
                left[0][1]=points[1][1];
                left[0][2]=points[1][2];
                left[0][3]=points[1][3];

                right[0][0]=points[0][0];
                right[0][1]=points[0][1];
                right[0][2]=points[0][2];
                right[0][3]=points[0][3];
            }
            else if(points[0][root->dim] < points[1][root->dim])
            {
                //cout<<"not here"<<endl;
                right[0][0]=points[1][0];
                right[0][1]=points[1][1];
                right[0][2]=points[1][2];
                right[0][3]=points[1][3];

                left[0][0]=points[0][0];
                left[0][1]=points[0][1];
                left[0][2]=points[0][2];
                left[0][3]=points[0][3];
            }
        }


        if (dim==0)
            dim = 1;
        else
            dim = 0;
        
        root->left = newNode();
        root->left->parent = root;
        tree(root->left, left, 1, dim );
        //cout<<"you and"<<endl;
        
        
        root->right = newNode();
        root->right->parent = root;
        tree(root->right, right, 1, dim );
        //cout<<" me "<<endl;
    }
    else
    {
        //cout<<"else "<<endl;
        float left1[n][4] = {};
        float right1[n][4] = {};
        int z=0;
        int l=0;
        for (int j =0; j< n ; j++)
        {
            //cout<<points[j][dim]<<endl;
            //cout<<root->num<<endl;
            if(points[j][dim] < root->num)
            {
                //cout<<"alo"<<endl;
                left1[z][0] =  points[j][0];
                left1[z][1] =  points[j][1];
                left1[z][2] =  points[j][2];
                left1[z][3] =  points[j][3];
                z++;
            }
            else
            {
                //cout<<"yoboseyo"<<endl;
                right1[l][0] =  points[j][0];
                right1[l][1] =  points[j][1];
                right1[l][2] =  points[j][2];
                right1[l][3] =  points[j][3];
                l++;
            }
            
            
        }
        float left[z][4] = {};
        float right[l][4] = {};
        for(int h=0 ; h<z ; h++)
        {
            left[h][0] =  left1[h][0];
            left[h][1] =  left1[h][1];
            left[h][2] =  left1[h][2];
            left[h][3] =  left1[h][3];
        }
        for(int h=0 ; h<l ; h++)
        {
            right[h][0] =  right1[h][0];
            right[h][1] =  right1[h][1];
            right[h][2] =  right1[h][2];
            right[h][3] =  right1[h][3];
        }
        
        int lsize = z;
        //cout<<lsize<<","<<n-lsize<<endl;

        //printArray(left, lsize);
        //printArray(right , n-lsize);
        
        if (dim==0)
            dim = 1;
        else
            dim = 0;
        
        if (lsize != 0)
        {
            root->left = newNode();
            root->left->parent = root;
            tree(root->left, left, lsize, dim  );
            //cout<<"this is"<<endl;
        }
        
        

        if (n-lsize != 0)
        {
            root->right = newNode();
            root->right->parent = root;
            tree(root->right, right, n-lsize, dim);
            //cout<<" me"<<endl;
        }
        
    }

    //cout<<" us "<<endl;
    //printArray(output,size);
    
};

float distance(float point1[2] , float point2[2])
{
    float distance = pow((point1[0] - point2[0]),2) + pow((point1[1] - point2[1]),2);
    distance = pow(distance,0.5);
    //distance = floorf(distance * 100) / 100;
    return distance;
}

Node* nearestNode;
float dist = Inf;
Node* nearest(Node* root, float point[2])  //output = min distance node
{
    int dim = root->dim;
    float temp[2] ={};
    //cout<<"first dist is"<<dist<<endl;
    //cout<<root->num<<endl;
    //cout<<root->point[0]<<endl;
    //cout<<"del tag is "<<root->right->deleted<<endl;
    if(root->right ==NULL && root->left ==NULL )
    {
        if(root->point[0]==Inf )
        {
            root = NULL;
        }

        else if(root->right ==NULL )
        {
            temp[0]=root->point[0];
            temp[1]=root->point[1];
            //cout<<"right node "<<temp[0]<<","<<temp[1]<<endl;
            //cout<<"this dist is "<<dist<<endl;
            if (dist > distance(temp , point))
            {
                dist = distance(temp , point);
                //output[0]=root->point[0];
                //output[1]=root->point[1];
                //cout<<"its"<<output[0]<<","<<output[1]<<endl;
                nearestNode = root;
                //cout<<"dist is "<<dist<<endl;
                return nearestNode;
            }
            
            
        }
        else if(root->left == NULL )
        {
            temp[0]=root->point[0];
            temp[1]=root->point[1];
            //cout<<"left node "<<temp[0]<<","<<temp[1]<<endl;
            if (dist > distance(temp , point))
            {
                dist = distance(temp , point);
                //output[0]=root->point[0];
                //output[1]=root->point[1];
                //cout<<output[0]<<","<<output[1]<<endl;
                nearestNode = root;
                //cout<<"hi"<<endl;
                return nearestNode;
            }
            //cout<<"dist is "<<dist<<endl;
        }
    }
    else
    {
        //cout<<"mmmm"<<endl;
        //cout<<root->num<<","<<point[dim]<<endl;
        if(point[dim] >= root->num )
        {
            //cout<<"yup"<<endl;
            if(root->right != NULL)
            {
                if(root->right->deleted == 0)
                {
                    //cout<<"not here"<<endl;
                    nearestNode = nearest(root->right, point );
                    //cout<<dist<<endl;
                }
            }
            
                
            //cout<<"now here"<<endl;
            //cout<<dist<<endl;
            if (abs(root->num - point[root->dim]) < dist)
            {
                //cout<<"i come here"<<endl;
                if(root->left != NULL && root->left->deleted == 0)
                {
                    //cout<<"what"<<endl;
                    nearestNode = nearest(root->left , point );
                }
            }
        }
        else if(point[dim] < root->num )
        {
            if(root->left !=NULL)
            {
                if(root->left->deleted == 0)
                    nearestNode = nearest(root->left, point);
                //cout<<"but now here"<<endl;
            }
            //cout<<root->num<<endl;
            //cout<<point[root->dim]<<endl;
            if (abs(root->num - point[root->dim]) < dist)
            {
                //cout<<"halo"<<endl;
                if(root->right != NULL && root->right->deleted == 0)
                    nearestNode = nearest(root->right , point);
            }
        }
    }
    
    return nearestNode;
}



int readFile(float points[][4], int n , string filename)
{
    string myText;

    fstream fin(filename);
    
    int x;
    fin >> x;
    //cout<<n<<endl;
    int index=0;
    for (int i = 0; i < n; i++) {
       
    
        fin >> points[i][0];
        
        fin >> points[i][1];
        points[i][2] = i+1;
        fin>>points[i][3];
        if(points[i][3]==1)
        {
            //cout<<"hehe"<<endl;
            index++;;
        }
        
        
        //cout<<points[i][0]<<","<<points[i][1]<<endl;
            
        
    }
    return index;
}
void findindex(float points[][4] , int n, int indexes[] , int s)
{
    //cout<<s<<endl;
    int i=1;
    int j;
    while(i <= s)
    {
        if(i==1)
        {
            j=0;
        }
        else
        {
            j = indexes[i-2];
        }
        while(j< n)
        {
            if(points[j][3] == i+1)
            {
                indexes[i-1] = j;
                break;
            }
            else
            {
                indexes[i-1] = n;
            }
            j++;
        }
        i++;
        //cout<<"indexes is "<<indexes[i-2]<<endl;
    }
}
int insertNode(Node * root ,Node * ins)
{
    float point[2];
    bool dim;
    point[0] = ins->point[0];
    point[1] = ins->point[1];
    while(root->left != NULL)
    {
        dim = root->dim;
        if(point[dim] < root->num)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    Node* node = newNode();
    node->parent = root->parent;
    //grandpar to node left or right
    if (root->parent->left == root)
    {
        root->parent->left = node;
    }
    else
    {
        root->parent->right = node;
    }
    //
    if (dim == 0)
    {
        dim = 1;
    }
    else
    {
        dim = 0;
    }
    node->dim = dim;
    if(root->point[dim] < point[dim])
    {
        node->num = point[dim];
        node->left = root;
        root->parent = node;
        node->right = ins;
        ins->parent = node;
    }
    else
    {
        node->num = root->point[dim];
        node->left = ins;
        ins->parent = node;
        node->right = root;
        root -> parent = node;

    }
    
    
}
Node* foundNode;
int deleteNode(Node *delNode)

{
    //cout<<"delete is called"<<endl;
    delNode->deleted = 1;
    if (delNode->parent->left == delNode)
    {
        if(delNode->parent->right == NULL || delNode->parent->right->deleted == 1)
        {
            if(delNode->parent->parent->left == delNode->parent)
            {
                delNode->parent->parent->left = NULL;
            }
            else if(delNode->parent->parent->right == delNode->parent)
            {
                delNode->parent->parent->right = NULL;
            }
        }
    }

    else if (delNode->parent->right == delNode)
    {
        if(delNode->parent->left == NULL || delNode->parent->left->deleted == 1)
        {
            if(delNode->parent->parent->left == delNode->parent)
            {
                delNode->parent->parent->left = NULL;
            }
            else if(delNode->parent->parent->right == delNode->parent)
            {
                delNode->parent->parent->right = NULL;
            }
        }
    }

    return 0;
}

//map<int , <int , int>> dict;

float mst(Node* root ,float points[][4] ,long int n )
{
    //cout<<root->right->num<<endl;
    float temp[2]={};
    float temp1[2]={};
    float temp2[2]={};
    float visited[n][2]={};
    Node* mynode;
    Node* mynode1;
    
    temp1[0]=points[0][0];
    temp1[1]=points[0][1];
    visited[0][0] = temp1[0];
    visited[0][1] = temp1[1];
    dist = Inf;
    mynode = nearest(root, temp1 );
    //cout<<"ok"<<endl;
    //cout<<mynode->parent->left->point[1]<<endl;
    deleteNode(mynode);
    //cout<<mynode->deleted<<endl;
    //cout<<root->right->right->right->right->deleted<<endl;
    //cout<<root->right->right->deleted<<endl;
    int vsize = 1;
    
    float totaldist = 0;
    while(vsize<n)
    {
        //cout<<"\n\n\n\n\n\n\n"<<vsize<<endl;
        //printArray(visited , vsize);
        float d = Inf;
        for(int i=0; i<vsize; i++)
        {
            temp1[0] = visited[i][0];
            temp1[1] = visited[i][1];
            dist = Inf;
            mynode1 = nearest(root, temp1 );
            temp2[0]=mynode1->point[0];
            temp2[1]=mynode1->point[1];
            
            //cout<<mynode1->deleted<<endl;
            //cout<<"\n\n\n"<<i<<d<<endl;
            if(distance(temp1 , temp2) < d )
            {
                temp[0] = temp2[0];
                temp[1] = temp2[1];
                mynode = mynode1;
                d = distance(temp1 , temp2);
                //cout<<"what u doin "<<d<<endl;
                //cout<<temp[0]<<","<<temp[1]<<endl;
            }
            
        }
        //dict[temp1] = <int, int>temp;
        //dict[temp] = temp1;
        visited[vsize][0]=temp[0];
        visited[vsize][1]=temp[1];
        deleteNode(mynode);
        vsize++;
        //cout<<"this node is "<<temp[0]<<","<<temp[1]<<endl;
        //cout<<"this one is "<<d<<endl;
        totaldist += d;
        //cout<<"\n\n\n\n\n\n\n\n\n\n\n\n"<<totaldist<<endl;
        //cout<<vsize<<endl;
    }
    return totaldist;
}

void phase1a(int index , long int n, float points[][4])
{
    float cities[index][2];
    for(int i =0; i<n; i++)
    {
        for(int j =0; j< index ; j++)
        {
            cities[j][0] = points[i][0];
            cities[j][1] = points[i][1];
        }
    }
}

void phase1c(float points[][4] , int indexes[] ,int n, int s)
{
    float temp1[2];
    float temp2[2];
    float d;
    d=0;
    for(int i=0; i< n ; i++)
    {
        temp1[0] = 0.0435;
        temp1[1] = -0.0790;
        temp2[0] = points[i][0];
        temp2[1] = points[i][1];
        d+=distance(temp1 , temp2);


    }
    cout<<d<<endl;
    int index;
   
    
    
    for( int i =0; i<s; i++)
    {
        if(i==0)
        {
            index = indexes[0];
        }
            
        else
        {
            index = indexes[i]- indexes[i-1];
        }
            
        //cout<<index<<endl;
        float cities[index][4];
        
        //cout<<dists[2]<<endl;
        for(int j =0 ; j<index ; j++)
        {
            if(i==0)
            {
                cities[j][0]=points[j ][0];
                cities[j][1]=points[j ][1];
            }
            else
            {
                cities[j][0]=points[j + indexes[i-1]][0];
                cities[j][1]=points[j + indexes[i-1]][1];
            }
            
            
        }
        float distss = Inf;
        int city;
        for(int j=0 ; j < index ; j++)
        {
            d=0;
            temp1[0] = cities[j][0];
            temp1[1] = cities[j][1];
            //cout<<"temp1 is "<<temp1[0]<<","<<temp1[1]<<endl;
            for(int x=0; x<index ; x++)
            {
                temp2[0] = cities[x][0];
                temp2[1] = cities[x][1];
                if(d < distance(temp1 , temp2))
                    d = distance(temp1 , temp2);
                //cout<<"here is "<<d<<endl;
            }
            //cout<<dists<<" and "<<d<<endl;
            if(distss > d)
            {
                distss = d;
                city = j+1;
            }
            //dists[j] = d;
            //cout<<"city is "<<city<<" dist is "<<distss<<endl;
        }
        
        if(i!=0)
            city = city + indexes[i-1] ;
        cout<<i+1<<": "<<city<<endl;
    }
    
}   

float phase2a( long int n , float points[][4] , int s , int indexes[])
{
    float d=0;
    
    float tempdist;
    int index;
    Node* states[s];
    for(int i=0 ; i<s;i++)
        states[i] = newNode();
    //int statenum=0;
    for( int i =0; i<s; i++)
    {
        if(i==0)
        {
            index = indexes[0];
        }
            
        else
        {
            index = indexes[i]- indexes[i-1];
        }
           
        float cities[index][4];
        
        for(int j =0 ; j<index ; j++)
        {
            if(i==0)
            {
                cities[j][0]=points[j ][0];
                cities[j][1]=points[j ][1];
            }
            else
            {
                cities[j][0]=points[j + indexes[i-1]][0];
                cities[j][1]=points[j + indexes[i-1]][1];
            }
        }
        int dis ;
        for (int j=0; j<index ;j++ )
        {
            if(s!=1)
            {
                dis = Inf;
                float temp1[2];
                int city;
                temp1[0]= cities[j][0];
                temp1[1]= cities[j][1];

                tempdist = Inf;
                int tempindex;
                int start;
                int end;
                end = indexes[i];
                if(i==0)
                    start = 0;
                else
                {
                    start = indexes[i-1];
                }
                
                for(int x=0; x<start; x++)
                {
                    float temp2[2];
                    temp2[0] = points[x][0];
                    temp2[0] = points[x][0];
                    if (distance(temp1 , temp2) < tempdist)
                    {
                        tempdist = distance(temp1 , temp2);
                        tempindex = x;
                    }
                
                }

                for(int x=end ; x<n; x++)
                {
                    float temp2[2];
                    temp2[0] = points[x][0];
                    temp2[0] = points[x][0];
                    if (distance(temp1 , temp2) < tempdist)
                    {
                        tempdist = distance(temp1 , temp2);
                        tempindex = x;
                    }
                }
                if(tempdist < dis)
                {
                    dis = tempdist;
                    city = tempindex;
                }
            }
            else
            {
                d=0;
                dis=0;
            }
            
        }
        //cout<<"hi"<<endl;
        //cout<<indexes[0]<<endl;
        //cout<<dis<<endl;
        
        tree(states[i], cities, index , 0);
        //cout<<states->point[0]<<endl;
        //cout<<"before mst"<<endl;
        //cout<<i<<endl;
        //cout<<index<<endl;
        if(index != 1)
        {
            d+=mst(states[i] , cities , index);
            //cout<<i<<endl;
            //cout<<"d is "<<d<<endl;
        }
        if(dis!=Inf)
            d+=dis;
        
    }
   
    return d;
}

float phase2b( long int n , float points[][4] , int s , int indexes[])
{
    float d=0;
    
    float tempdist;
    int index;
    Node* states[s];
    for(int i=0 ; i<s;i++)
        states[i] = newNode();
    //int statenum=0;
    for( int i =0; i<s; i++)
    {
        if(i==0)
        {
            index = indexes[0];
        }
            
        else
        {
            index = indexes[i]- indexes[i-1];
        }
           
        float cities[index][4];
        
        for(int j =0 ; j<index ; j++)
        {
            if(i==0)
            {
                cities[j][0]=points[j ][0];
                cities[j][1]=points[j ][1];
            }
            else
            {
                cities[j][0]=points[j + indexes[i-1]][0];
                cities[j][1]=points[j + indexes[i-1]][1];
            }
        }
        int dis ;
        
        if(s!=1)
        {
            dis = Inf;
            float temp1[2];
            int city;
            temp1[0]= cities[index/2][0];
            temp1[1]= cities[index/2][1];

            tempdist = Inf;
            int tempindex;
            int start;
            int end;
            end = indexes[i];
            if(i==0)
                start = 0;
            else
            {
                start = indexes[i-1];
            }
            
            for(int x=0; x<start; x++)
            {
                float temp2[2];
                temp2[0] = points[x][0];
                temp2[0] = points[x][0];
                if (distance(temp1 , temp2) < tempdist)
                {
                    tempdist = distance(temp1 , temp2);
                    tempindex = x;
                }
            
            }

            for(int x=end ; x<n; x++)
            {
                float temp2[2];
                temp2[0] = points[x][0];
                temp2[0] = points[x][0];
                if (distance(temp1 , temp2) < tempdist)
                {
                    tempdist = distance(temp1 , temp2);
                    tempindex = x;
                }
            }
            if(tempdist < dis)
            {
                dis = tempdist;
                city = tempindex;
            }
        }
        else
        {
            d=0;
            dis=0;
        }
            
        
        //cout<<"hi"<<endl;
        //cout<<indexes[0]<<endl;
        //cout<<dis<<endl;
        
        tree(states[i], cities, index , 0);
        //cout<<states->point[0]<<endl;
        //cout<<"before mst"<<endl;
        //cout<<i<<endl;
        //cout<<index<<endl;
        if(index != 1)
        {
            d+=mst(states[i] , cities , index);
            //cout<<i<<endl;
            //cout<<"d is "<<d<<endl;
        }
        if(dis!=Inf)
            d+=dis;
        
    }
   
    return d;

}
void phase1a(float points[][4] , int n )
{
    tree(root , points, n, 0);
    float dis;
    dis = mst(root , points , n);
    dis = floorf(dis * 100) / 100;
    cout<<dis<<endl;
}
int s;
int main() 
{ 
    string filename;
    filename = "dataset0.in";
    fstream fin(filename);
    long int n;
    fin >> n;
    //float points[n][4]={};
    int index;
    index = readFile(pointsss , n, filename);
	s = pointsss[n-1][3];
    int indexes[s];
    findindex(pointsss , n , indexes , s);

    //for running each phase and parts please uncomment any of lines below//
    // 2 parts must not be uncommented at once//

    // phase 1a         //complexity of implementing kd-tree is n(logn)^2 so this phase has complexity of O(n(log^2(n))) .
    phase1a(pointsss , n);
    

    //phase 1c            
    //phase1c(pointsss , indexes , n , s);


    //phase2a                            // s: number of states    complexity ~ O(n^2 + n(log^2(n)))    which is worse than phase 1a                            
    //float f;                                                  //memory : O(nlogn) as we are using balanced kd tree
    //f = phase2a(n , pointsss , s , indexes);
    //f = floorf(f*100)/100;
    //cout<<f<<endl;

   //phase 2b                                      //complexity is O(n^2) 
    //float f;                                        //faster than previous step as it does not search all nodes for each states nearest city.
    //f = phase2b( n , pointsss , s , indexes);
    //f = floorf(f*100)/100;
    //cout<<f;




	return 0; 
} 
