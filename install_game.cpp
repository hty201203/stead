#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<queue>
#define MAX1 1000000005
#define MAX2 200005
#define MAX3 100005
//#include<conio.h>
using namespace std;
struct game{
	char name[50];
	int ver[4];
	char a[100];
	string b;
	void prtv(){
		cout<<"game name:"<<name<<"\n";
		printf("ver%d.%d.%d.%d\n",ver[0],ver[1],ver[2],ver[3]);
	}
	bool cmpv(game a){
		if(a.ver[0]>ver[0]) return 0;
		if(a.ver[1]>ver[1]) return 0;
		if(a.ver[2]>ver[2]) return 0;
		if(a.ver[3]>=ver[3]) return 0;
		return 1;
	}
};
game g[100];
game t;
string fd,md;
void write(int n){
	system("del games.cfg");
	fstream gml("games.cfg",ios::out);
	gml<<n<<"\n";
	for(int i = 0;i<n;i++){
		cout<<"write game no."<<i<<"\n";
		gml<<g[i].name<<"\n";
		for(int j = 0;j<4;j++) gml<<g[i].ver[j]<<" ";
		gml<<"\n";
		gml<<g[i].a<<"\n"<<g[i].b<<"\n";
	}
}
int main(){
	fstream gcfg("install\\game.cfg",ios::in);
	fstream inst("install\\install.cfg",ios::in);
	fstream gml("games.cfg",ios::in);
	system("echo off & cls");
	system("title stead_game_centre");
	printf("press to install game\n");
	printf("you should copy the game to \\install first!\n");
	system("pause");
	string ne;
	inst>>ne>>fd>>md;
	cout<<"game name:"<<ne<<"\n";
	cout<<"game fd:"<<fd<<"\n";
	cout<<"game md:"<<md<<"\n";
	int n;
	gml>>n;
	for(int i = 0;i<n;i++){
		gml>>g[i].name;
		gml>>g[i].ver[0]>>g[i].ver[1]>>g[i].ver[2]>>g[i].ver[3];
		gml>>g[i].a>>g[i].b;
		printf("========game%3d========\n",i);
		cout<<g[i].name<<"\n";
		printf("ver%d.%d.%d.%d\n",g[i].ver[0],g[i].ver[1],g[i].ver[2],g[i].ver[3]);
		cout<<g[i].a<<"\n";
	}
	cout<<"=======================\n";
	gcfg>>t.name>>t.ver[0]>>t.ver[1]>>t.ver[2]>>t.ver[3];
	gcfg>>t.a>>t.b;
	g[n]=t;
	n++;
	printf("GAME LOADED\n");
	for(int i = 0;i<n;i++){
		gml>>g[i].name;
		gml>>g[i].ver[0]>>g[i].ver[1]>>g[i].ver[2]>>g[i].ver[3];
		gml>>g[i].a>>g[i].b;
		printf("========game%3d========\n",i);
		cout<<g[i].name<<"\n";
		printf("ver%d.%d.%d.%d\n",g[i].ver[0],g[i].ver[1],g[i].ver[2],g[i].ver[3]);
		cout<<g[i].a<<"\n";
	}
	cout<<"=======================\n";
	printf("COPY..\n");
	string s1 = "copy install\\ game\\";
	string s2 = fd;
	string s3 = s1+s2;
	string b1 = "md game\\";
	string c1 = b1+md;
	string d1 = "md save\\";
	string d2 = d1+md;
	string e1 = "del game\\"+fd+"*.* /F /S /Q";
	cout<<s3<<"\n"<<c1<<"\n"<<d2<<"\n";
	int r1,r2,r3,r4;
	r1 = system(c1.c_str());
	r3 = system(d2.c_str());
	string f1 = "xcopy /E /C /G /R install\\ game\\"+fd;
	//system(f1.c_str());
	if(r1==1 || r3==1){
		printf("DIR FOUND!STOP INSTALL!\n该游戏已安装\n");
		int x;
		printf("是否覆盖安装？<0/1>:");
		cin>>x;
		if(x==1){
			//cout<<"功能未完善\n";
			int i;//同名游戏编号
			n--;
			cout<<"n:"<<n<<"\n";
			for(i = 0;i<n;i++){
				printf("finding|i:%3d|",i);
				cout<<g[i].name<<" "<<t.name<<"\n";
				if(strcmp(g[i].name,t.name)==0) break;
			}
			printf("found game : NO.%d\n",i);
			cout<<"OLD:\n";
			g[i].prtv();
			cout<<"NEW:\n";
			t.prtv();
			int r = t.cmpv(g[i]);
			if(r==0){
				printf("你想更新到旧版本吗？<0/1>");
				int y;
				cin>>y;
				if(y==0){
					printf("ended r1:%d r2:%d r3:%d r4:%d\n",r1,r2,r3,r4);
					system("pause");
				}
			}
			g[i]=t;
			printf("清空目标目录\n");
			r4 = system(e1.c_str());
			printf("更新版本数据\n");
			system(f1.c_str());
			gml.close();
			write(n);
			printf("更新版本文件\n");
			r2 = system(s3.c_str());
		}
		else printf("exit\n");
	}
	else{
		printf("清空目标目录\n");
		r4 = system(e1.c_str());
		printf("WRITE..\n");
		system(f1.c_str());
		gml.close();
		write(n);
		r2 = system(s3.c_str());
	}
	printf("ended r1:%d r2:%d r3:%d r4:%d\n",r1,r2,r3,r4);
	system("pause");
	return 0;
}

