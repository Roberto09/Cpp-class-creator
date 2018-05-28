#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale> 
using namespace std;
std::locale loc;


//Structure for the Attributes of the class
struct Attribute{
	char type;
	string name;
};

//Function to convert a string to uppercase
string toUpper(string str){
  string newStr = "";
  for (std::string::size_type i=0; i<str.length(); ++i)
    newStr = newStr + std::toupper(str[i],loc);
  return newStr;
}


int main(){

	ofstream outputClass;

	string className = "";
	vector<Attribute> Variables;

	cout << "Type the name of your class: ";
	cin >> className;

	outputClass.open(className + ".h");

	//Asking the User to input data to add into the header of the .h
	string classNameCreator;
	string id;
	string date;
	cout << "Type your name: " << endl;
	cin.ignore();
	getline(cin, classNameCreator);
	cout << "Type your id number: ";
	cin >> id;
	cout << "Type the date mm/dd/yyyy (with no spaces): ";
	cin >> date;
	outputClass << "//Class: " << className << endl << "//Created by: " << classNameCreator << " Id number: " << id << endl;
	outputClass << "//Date: " << date << endl << endl;




	//Asking the user to input the types and names of the attributes
	cout << "Type in the attributes: " << endl;
	char type;

	while(type != '0'){
	string name;
	cout << "------" << endl;
	cout << "Type: 'i' = int, 'd' = double, 'b' = bool, 'c' = char, 's' = string --- (if you are done just type '0')";
	cin >> type;
	if (type == '0')
		continue;
	cout << "Name of the attribute:";
	cin >> name;
	Attribute atr;
	atr.type = type;
	atr.name = name;
	Variables.push_back(atr);
	}

	//Starting to write the header and the libraries to the .h
	outputClass << "#ifndef " << toUpper(className) << "_H_INCLUDED" << endl;
	outputClass << "#define " << toUpper(className) << "_H_INCLUDED" << endl;
	outputClass << endl << "#include <iostream>" << endl << "#include <string>" << endl << endl << "using namespace std;" << endl << endl;


	//Starting to write the class into the .h
	outputClass << "class " << className << "{" << endl;

	outputClass << endl << "//Methods" << endl;
	outputClass << "public: " << endl;

	outputClass << "\t" << "//Constructors" << endl;

	//Writing header of Default Constructor
	outputClass << "\t" << "//Default Constructor" << endl << "\t" << className << "();" << endl;

	//Start writing header of the Constructor with Parameters
	outputClass << "\t" << "//Contructor with parameters" << endl << "\t" << className << "(";
	string parameters = "";

	//Writing parameters in a string to further write them to the class in the constructor with parameters
	for(int i = 0; i < Variables.size(); i++){
		if(Variables[i].type == 'i'){
			parameters = parameters + "int";
		}
		else if(Variables[i].type == 'd'){
			parameters = parameters + "double";
		}
		else if(Variables[i].type== 'b'){
			parameters = parameters + "bool";	
		}
		else if(Variables[i].type == 's'){
			parameters = parameters + "string";
		}
		else if(Variables[i].type == 'c'){
			parameters = parameters +  "char";
		}
		else{
			continue;
		}
		parameters = parameters + ", ";	
	}

	//Erasing last " ," from the parametters
	parameters = parameters.substr(0, parameters.length()-2);

	//writing parameters to the Constructor with parameters
	outputClass << parameters << ");" << endl;
	

	//Writing header of 'get' methods as pubic to the class example: Type getAttribute();

	outputClass << endl << "\t" << "//Getter Methods" << endl;
	for(int i = 0; i < Variables.size(); i ++){
		if(Variables[i].type == 'i'){
			outputClass <<"\t" <<  "int ";
		}
		else if(Variables[i].type == 'd'){
			outputClass <<"\t" <<  "double ";
		}
		else if(Variables[i].type== 'b'){
			outputClass <<"\t" <<  "bool ";	
		}
		else if(Variables[i].type == 's'){
			outputClass <<"\t" <<  "string ";
		}
		else if(Variables[i].type == 'c'){
			outputClass <<"\t" <<  "char ";
		}
		else{
			continue;
		}
		outputClass <<"get" << std::toupper(Variables[i].name[0], loc) << Variables[i].name.substr(1,Variables[i].name.length()-1) << "();" << endl;
	}

	//Writing header of 'set' methods as public to the class example: void setAttribute(Type newValue);
	outputClass << endl << "\t" << "//Setter Methods " << endl;
	for(int i = 0; i < Variables.size(); i ++){
		string type1;

		if(Variables[i].type == 'i'){
			outputClass << "\t" << "void ";
			type1 = "int";
		}
		else if(Variables[i].type == 'd'){
			outputClass <<"\t" <<  "void ";
			type1 = "double";
		}
		else if(Variables[i].type== 'b'){
			outputClass <<"\t" <<  "void ";	
			type1 = "bool";
		}
		else if(Variables[i].type == 's'){
			outputClass <<"\t" <<  "void ";
			type1 = "string";
		}
		else if(Variables[i].type == 'c'){
			outputClass <<"\t" <<  "void ";
			type1 = "char";
		}
		else{
			continue;
		}
		outputClass << "set" << std::toupper(Variables[i].name[0], loc) << Variables[i].name.substr(1,Variables[i].name.length()-1) << "(" << type1 <<");" << endl;
	}
	outputClass << endl;

	//Writing attributes into the class as private
	outputClass << "//Attributes" << endl;
	outputClass << "private: " << endl;
	for(int i = 0; i < Variables.size(); i ++){
		if(Variables[i].type == 'i'){
			outputClass << "\t" <<  "int ";
		}
		else if(Variables[i].type == 'd'){
			outputClass << "\t" <<  "double ";
		}
		else if(Variables[i].type== 'b'){
			outputClass << "\t" <<  "bool ";	
		}
		else if(Variables[i].type == 's'){
			outputClass <<"\t" <<  "string ";
		}
		else if(Variables[i].type == 'c'){
			outputClass <<"\t" <<  "char ";
		}
		else{
			continue;
		}
		outputClass << Variables[i].name << ";" << endl;
	}
	outputClass << "};" << endl << endl << "//Development of Methods" << endl;



	//Developing Default Constructor outside the class
	outputClass << "//Constructors" << endl;
	outputClass << "//Default Constructors" << endl << className << "::" << className << "(){" << endl;

	for(int i = 0; i < Variables.size(); i++){
		if(Variables[i].type == 'i'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << "0;" << endl;
		}
		else if(Variables[i].type == 'd'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << "0;" << endl;
		}
		else if(Variables[i].type== 'b'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << "false;" << endl;	
		}
		else if(Variables[i].type == 's'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << "\"\";" << endl;
		}
		else if(Variables[i].type == 'c'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << "\' \';" << endl;
		}
		else{
			continue;
		}
	}
	outputClass << "}" << endl << endl;

	//Developing Contructor with parameters outside the class in the .h
	outputClass << "//Contructor" << endl << className << "::" << className << "(";
	string parameters2 = "";
	for(int i = 0; i < Variables.size(); i++){
		if(Variables[i].type == 'i'){
			parameters2 = parameters2 + "int ";
		}
		else if(Variables[i].type == 'd'){
			parameters2 = parameters2 + "double ";
		}
		else if(Variables[i].type== 'b'){
			parameters2 = parameters2 + "bool ";	
		}
		else if(Variables[i].type == 's'){
			parameters2 = parameters2 + "string ";
		}
		else if(Variables[i].type == 'c'){
			parameters2 = parameters2 +  "char ";
		}
		else{
			continue;
		}
		parameters2 = parameters2 + Variables[i].name + ", ";	
	}
	parameters2 = parameters2.substr(0, parameters2.length()-2);
	outputClass << parameters2 << "){" << endl;

	for(int i = 0; i < Variables.size(); i ++){
		if(Variables[i].type == 'i'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << Variables[i].name+ ";" << endl;
		}
		else if(Variables[i].type == 'd'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << Variables[i].name+ ";" << endl;
		}
		else if(Variables[i].type== 'b'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << Variables[i].name+ ";" << endl;	
		}
		else if(Variables[i].type == 's'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << Variables[i].name+ ";" << endl;
		}
		else if(Variables[i].type == 'c'){
			outputClass << "\t" << "this -> " << Variables[i].name << " = " << Variables[i].name+ ";" << endl;
		}
		else{
			continue;
		}
	}
	outputClass << "}" << endl;

	//Developing Get methods outside the class in the .h
	outputClass << endl << "//Getter Methods" << endl;
	for(int i = 0; i < Variables.size(); i ++){
		if(Variables[i].type == 'i'){
			outputClass <<  "int " << className << "::";
		}
		else if(Variables[i].type == 'd'){
			outputClass <<  "double " << className << "::";
		}
		else if(Variables[i].type== 'b'){
			outputClass <<  "bool " << className << "::";	
		}
		else if(Variables[i].type == 's'){
			outputClass <<  "string " << className << "::";
		}
		else if(Variables[i].type == 'c'){
			outputClass <<  "char " << className << "::";
		}
		else{
			continue;
		}
		outputClass <<"get" << std::toupper(Variables[i].name[0], loc) << Variables[i].name.substr(1,Variables[i].name.length()-1) << "(){" << endl;
		outputClass << "\t" << "return " << Variables[i].name << ";" << endl << "}" << endl << endl;
	}
	outputClass << endl;

	//Developing set mehtods outside the class
	outputClass << endl << "//Setter Methods" << endl;
	for(int i = 0; i < Variables.size(); i ++){
		string type1;

		if(Variables[i].type == 'i'){
			outputClass << "void " << className << "::";
			type1 = "int";
		}
		else if(Variables[i].type == 'd'){
			outputClass <<  "void " << className << "::";
			type1 = "double";
		}
		else if(Variables[i].type== 'b'){
			outputClass <<  "void " << className << "::";	
			type1 = "bool";
		}
		else if(Variables[i].type == 's'){
			outputClass <<  "void " << className << "::";
			type1 = "string";
		}
		else if(Variables[i].type == 'c'){
			outputClass <<  "void " << className << "::";
			type1 = "char";
		}
		else{
			continue;
		}
		outputClass << "set" << std::toupper(Variables[i].name[0], loc) << Variables[i].name.substr(1,Variables[i].name.length()-1) << "(" << type1 << " " << Variables[i].name << "){" << endl;
		outputClass << "this -> " << Variables[i].name << " = " << Variables[i].name << ";" <<endl;
		outputClass << "}" << endl << endl;
	}

	//Writing the ending of the class definition
	outputClass << endl << "#endif";

	//Closing the .h file
	outputClass.close();


	return 0;
}