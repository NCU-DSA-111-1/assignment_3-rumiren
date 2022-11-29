#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<time.h>
#include<iomanip>
#include "huffman.h"
#include "arc.h"

using namespace std;

int main(){
    int n;
	cout<<"Enter number of characters: ";
	cin>>n;
    char Harr[n];
    int freq[n];
    int sum=0;
    cout<<"Enter the characters and thier frequency in order:\n";
    for(int i=0; i<n; i++){
        cin>>Harr[i];
        cin>>freq[i];
        sum+=freq[i];
    }
	unordered_map<char, node> arr;
	vector<char> ar;
	double range_from= 0;
	for(int i=0; i<n; i++){
		ar.push_back(Harr[i]);
		arr[Harr[i]].prob=(double)freq[i]/(double)sum;
		arr[Harr[i]].range_from= range_from;
		arr[Harr[i]].range_to= range_from+ arr[Harr[i]].prob;
		range_from= arr[Harr[i]].range_to;
	}

    cout<<"\nTest the Huffman coding.\n";
    int size = sizeof(Harr) / sizeof(Harr[0]);
    double START1,END1;
    START1 = clock();
    HuffmanCodes(Harr, freq, size);
    END1 = clock();
    cout << "The time Huffman coding spend is "<<(END1 - START1) / CLOCKS_PER_SEC << " s" << endl;

    cout<<"\nTest the Arithmetic coding.\n";
	cout<<"Symbol"<<setw(12)<<"Probability"<<setw(12)<<"Range_from"<<setw(12)<<"Range_to\n";
	cout<<"----------------------------------------------------\n";
	for(int i=0; i<ar.size(); i++){
		char ch= ar[i];
		cout<<setw(6)<<ch<<setw(12)<<arr[ch].prob<<setw(12)<<arr[ch].range_from<<setw(12)<<arr[ch].range_to<<endl;
	}
	cout<<endl;
	string s;
	cout<<"Enter text: ";
	cin>>s;
    double START2,END2;
    START2 = clock();
	double code_word= encoding(arr, s);
    END2 = clock();
	cout<<"Code word for "<<s<<" is: "<<code_word<<endl;
    cout << "The time Arithmetic coding spend is "<< (END2 - START2) / CLOCKS_PER_SEC << " s"<< endl;
}