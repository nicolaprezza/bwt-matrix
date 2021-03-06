/*
 * bwt-matrix.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: nico
 */

#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int,string> suf;

string left_rotate(string s){

	return s.substr(1) + s[0];

}

string reverse(string s){

	string s1 = s;

	for(int i=s.length()-1;i>=0;--i)
		s1[s.length()-i-1] = s[i];

	return s1;

}

int main(int argc, char** argv){

	if(argc<2 or argc >3){

		cout << "Outputs latex code to print the BWT matrix of input string." << endl;
		cout << "Usage:" << endl;
		cout << "	bwt-matrix <input_string> [rev]" << endl;
		cout << "	<input_string>	input string. must NOT contain # (used as terminator)." <<endl;
		cout << "	[rev]	(optional): if 'rev' specified here, compute BWT matrix of reverse string."<<endl<<endl;

		exit(0);

	}

	string input = string(argv[1]);

	bool rev=false;

	input = input + '#';

	if(argc>2 and string(argv[2]).compare("rev")==0){

		rev=true;
		input = reverse(input);

	}

	auto comp = [](suf x, suf y){ return x.second.compare(y.second) < 0; };
	std::set<suf,decltype(comp)> rotations(comp);

	string current_rotation = string(input);

	for(int i=0;i<input.size();++i){

		rotations.insert({((rev?input.size()-i:i-1)+input.size())%input.size(),current_rotation});

		current_rotation = left_rotate(current_rotation);

	}

	vector<bool> runs;

	set<int> runs_i;//positions of run beginnings

	char last_c;

	int j=0;
	for(auto r : rotations){

		if(j==0){

			last_c = r.second[r.second.length()-1];//BWT character
			runs_i.insert(r.first);

		}else{

			char c = r.second[r.second.length()-1];//BWT character

			if(last_c!=c){

				runs_i.insert(r.first);

			}

			runs.push_back(last_c!=c);
			last_c = c;

		}

		j++;

	}

	runs.push_back(true);

	cout << "\\documentclass[]{article}" << endl;

	cout << "\\usepackage[margin=10pt]{geometry}" << endl;

	cout << "\\begin{document}" << endl;

	cout << "\\fontsize{2.2mm}{3.2mm}\\selectfont" << endl;
	cout << "\\setlength{\\tabcolsep}{1pt}" << endl;

	cout << "\\ \\\\" << endl;


	cout << "\\begin{center}";

	cout << "\\begin{tabular}{r || ";

	for(int i=0;i<input.length()-1;++i) cout << "c";

	cout << "| c }" << endl;
	cout << "\\hline" << endl;

	j=0;
	for(auto r : rotations){

		cout << (r.first+1)%input.length() << " & ";

		int k=0;
		for(auto c : r.second){

			cout << (c=='#'?"\\#":string()+c);
			if(k++<r.second.size()-1) cout << " & ";

		}

		cout << " \\\\ ";

		if(runs[j])
			cout << "\\hline" << endl;
		else
			cout << endl;

		j++;

	}

	cout << "\\end{tabular}" << endl;

	cout << endl << "\\ \\\\\\ \\\\" << endl << endl;

	cout << "\\setlength{\\tabcolsep}{1pt}" << endl;

	cout << "\\begin{tabular}{";

		for(int i=0;i<input.length();++i) cout << "c";

		cout << " }" << endl;

		for(int i=0;i<input.length();++i){

			cout << i;

			if(i<input.length()-1) cout << " & ";

		}

		cout << "\\\\" << endl;

		j=0;
		for(auto c:input){

			if(runs_i.find(j)!=runs_i.end()) cout << "\\underline{\\textbf{";
			if(c=='#') cout << "\\";
			cout << c;
			if(runs_i.find(j)!=runs_i.end()) cout << "}}";

			if(j<input.length()-1) cout << " & ";

			j++;

		}

		cout << "\\\\" << endl;

		cout << "\\end{tabular}" << endl;

		cout << "\\end{center}";

		cout << "\\end{document}"<<endl;

}



