#include<bits/stdc++.h>
using namespace std;
string tostring(int i)
{
	string ret = "";
	while(i!=0)
	{
		ret = (char)(i%10+'0') + ret;
		i/=10;
	}
	return ret;
}

int main()
{
	string name = ".\\";
	string newname = "real_";
	
	cout<<"輸入路徑(.\\)\n";
	cin>>name;
	cout<<"輸入命名前綴\n";
	cin>>newname;
	
	fstream file;	
	string ins_1 = "dir \"" + name + "\" /b /on >" + name + "\\list.txt";
	string ins_2 = name + "\\list.txt";

	string ins_3;
	cout<<ins_1<<endl;	
	system(ins_1.c_str());
	
	file.open(ins_2.c_str(), ios::in);
	
	vector<string> a;
	string tmp;
	while(file>>tmp)
	{
		a.push_back(tmp);
	}
	for(int i=0; i<a.size(); i++)
	{
		cout<<a[i]<<endl;
		ins_3 = "ren " + name + "\\" + a[i] + " " + newname + tostring(i+1)  + ".png";
		cout<<ins_3<<endl;
		system(ins_3.c_str());
	}
	
	return 0;
}
