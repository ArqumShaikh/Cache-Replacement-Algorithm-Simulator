#include <bits/stdc++.h>
#include "lru.h"
#include "fifo.h"
#include "arc.h"
#include "nru.h"

#include "PLRU.h"
//Command to run gzip -dc trace.gz | ./a.out fifo 4

using namespace std;

//long long int tagValue[1000000],setValue[1000000] ;

// declare cache properties here and send them to the function , funcyion call will now look like : (cache,valid,referenced,setnumber,tagnumber,noofways)
// also declare any other type of globally referenced data for any algorithm

long long int decimal(string temp)
{
    long long int sum = 0, p = 1;
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        sum += (temp[i] - '0') * p;
        p *= 2;
    }
    return sum;
}

string sintobin(char temp)
{
    switch (temp)
    {
    case '0':
        return "0000";
        break;
    case '1':
        return "0001";
        break;
    case '2':
        return "0010";
        break;
    case '3':
        return "0011";
        break;
    case '4':
        return "0100";
        break;
    case '5':
        return "0101";
        break;
    case '6':
        return "0110";
        break;
    case '7':
        return "0111";
        break;
    case '8':
        return "1000";
        break;
    case '9':
        return "1001";
        break;
    case 'a':
        return "1010";
        break;
    case 'b':
        return "1011";
        break;
    case 'c':
        return "1100";
        break;
    case 'd':
        return "1101";
        break;
    case 'e':
        return "1110";
        break;
    case 'f':
        return "1111";
        break;
    }
}

pair<long long int, long long int> hextodec(string s, int ways)
{
    string binary = "", binequi = "", setno = "", tagno = "";
    char temp;

    int waybits = log2(ways), i;
    long long int set, tag;
    for (i = 2; i < 14; i++)
    {
        temp = s[i];
        //cout<<temp<<"is temp  ";
        binequi = sintobin(temp);
        //cout<<binequi<<"is binary"<<endl;
        binary += binequi;
    }
    //cout<<binary<<" is binary "<<endl;
    for (i = 30 + waybits; i < 42; i++)
        setno += binary[i];

    for (i = 0; i < 30 + waybits; i++)
        tagno += binary[i];
    //cout<<setno<<" "<<tagno<<endl;
    set = decimal(setno);
    tag = decimal(tagno);
    //cout<<set<<"  "<<tag<<endl;
    return {tag, set};
}

pair<long long int, long long int> hextodecprint(string s, int ways)
{
    string binary = "", binequi = "", setno = "", tagno = "";
    char temp;

    int waybits = log2(ways), i;
    // cout<<waybits<<"is bits for ways\n";
    long long int set, tag;
    for (i = 2; i < 14; i++)
    {
        temp = s[i];
        //cout<<temp<<"is temp  ";
        binequi = sintobin(temp);
        //cout<<binequi<<"is binary"<<endl;
        binary += binequi;
    }

    // cout<<binary<<"is the bunary equi\n";
    //cout<<binary<<" is binary "<<endl;
    for (i = 30 + waybits; i < 42; i++)
        setno += binary[i];

    for (i = 0; i < 30 + waybits; i++)
        tagno += binary[i];
    //cout<<setno<<" "<<tagno<<endl;
    set = decimal(setno);
    tag = decimal(tagno);
    //cout<<set<<"  "<<tag<<endl;
    return {tag, set};
}

int stringtoint(string temp)
{
    int ans = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        ans = 10 * ans + (temp[i] - '0');
    }
    return ans;
}

int main(int argc, char **argv)
{

	int i,numberOfWays,blockSize;
	string algorithm,filename;
    int hitRatio,flag = 0;
    int SETNUMBER,counterMain = 0;
    long long int TAGNUMBER; 
	long long int read=0,size=0,hits = 0;
	string temp,type,word;
 
    for (i = 1; i < argc; i++)

    {
        if (i == 1)
            algorithm = argv[i];

        else if(i==2) numberOfWays=stringtoint(argv[i]);
     	else if(i==3) blockSize=stringtoint(argv[i]);
    }
    // fstream file;
    // file.open(filename.c_str());
    // int counter=0;
    cout<< algorithm << "\n" << numberOfWays << "\n";
	
	do
    { 
    	   cin >> temp;
           cin >> type;
           cin >> word;

           if(temp[0] == EOF)
                break;

           size++;
           
    	   if(type == "R")read++;
            
    	
    		
            
            	pair<long long int,long long int> p=hextodec(word,numberOfWays);
            TAGNUMBER = p.first;
            SETNUMBER = p.second;	
            
    	
        	// transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);
        	if(algorithm=="srrip")
        	{
        		//py
        	}
        	else if(algorithm=="rrp")
        	{
        		//ARC(tagValue,setValue,size,numberOfWays)*100;
        	}
        	else if(algorithm=="nru")
        	{
        		hitRatio = nru(TAGNUMBER,SETNUMBER,numberOfWays,blockSize);
                if(hitRatio == 1)
                    hits++;
                if(flag == 0){
                	cout << "inside nru \n";
                	flag =1;
                }
        	}
        	else if(algorithm=="lfu")
        	{
        		//arqum
        	}
        	else if(algorithm == "lru")
        	{
        		//shrinidhi
                // arguments to lru function: tagValue[size], setValue[size], size, numberOfWays
                // Giving error check it 
                if(flag == 0){
                	cout << "inside lru \n";
                	flag =1;
                }
                hitRatio = lru(TAGNUMBER,SETNUMBER,1,numberOfWays,blockSize); 
        		if(hitRatio == 1)
        			hits++;

        	}
        	else if(algorithm=="plru")
        	{
        		//chaitanya
        		hitRatio = plru(TAGNUMBER,SETNUMBER,numberOfWays,blockSize); 
        		if(hitRatio == 1)
        			hits++;
        	}
        	else if(algorithm=="fifo")
        	{

                // cout<<"hey";
        		// hitRatio = fifo(TAGNUMBER,SETNUMBER,1,numberOfWays);
          //       // cout<<result;
          //       if(hitRatio==1){

        		// float result = fifo(SETNUMBER,TAGNUMBER,1,numberOfWays);
          //       if(result==1){
          //           hits++;
            //    }
        	//}
            
=======
    cout << algorithm << "\n"
         << numberOfWays << "\n";

    do
    {
        cin >> temp;
        cin >> type;
        cin >> word;

        if (temp[0] == EOF)
            break;

        size++;

        if (type == "R")
            read++;

        pair<long long int, long long int> p = hextodec(word, numberOfWays);
        TAGNUMBER = p.first;
        SETNUMBER = p.second;

        // transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);
        if (algorithm == "srrip")
        {
            //py
        }
        else if (algorithm == "rrp")
        {
            //ARC(tagValue,setValue,size,numberOfWays)*100;
        }
        else if (algorithm == "nru")
        {
            hitRatio = nru(TAGNUMBER, SETNUMBER, numberOfWays, 64);
            if (hitRatio == 1)
                hits++;
            if (flag == 0)
            {
                cout << "inside nru \n";
                flag = 1;
            }
        }
        else if (algorithm == "lfu")
        {
            //arqum
        }
        else if (algorithm == "lru")
        {
            //shrinidhi
            // arguments to lru function: tagValue[size], setValue[size], size, numberOfWays
            // Giving error check it
            if (flag == 0)
            {
                cout << "inside lru \n";
                flag = 1;
>>>>>>> cc9e6d38eebf7006f9d4f84d0ccfc6631ca3b271
            }
            hitRatio = lru(TAGNUMBER, SETNUMBER, 1, numberOfWays, 64);
            if (hitRatio == 1)
                hits++;
        }
        else if (algorithm == "plru")
        {
            //chaitanya
            hitRatio = plru(TAGNUMBER, SETNUMBER, numberOfWays, 64);
            if (hitRatio == 1)
                hits++;
        }
        else if (algorithm == "fifo")
        {

            hitRatio = fifo(SETNUMBER, TAGNUMBER, 1, numberOfWays);
            // cout<<result;
            if (hitRatio == 1)
            {
                hits++;
            }
        }

    } while (true);

    cout << hits << "is number of hits " << size << "is total input\n";

    return 0;
}
