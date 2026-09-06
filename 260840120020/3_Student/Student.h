#ifndef STUDENT_H
#define STUDENT_H
class Student{
	private:
		//data members
		int sid,age;
		char *sname;
		double m1,m2,m3;
	public:
		//default constructor
		Student();
		//parameterized constructors
		Student(int sid,char *sname, int age);
		Student(int sid,char *sname, int age, double m1,double m2, double m3);
		// getter and setter for sid
		int getId();
		void setId(int id);
		// getter and setter for sname
		char* getName();
		void setName(char *name);
		//getter and setter for age
		int getAge();
		void setAge(int age);
		// getters for marks
		double getM1();
		double getM2();
		double getM3();
		//setters for marks
		void setM1(double marks);
		void setM2(double marks);
		void setM3(double marks);
		// Display student data
		void displayData();
		//calculate average of total marks
		double getAvg();

		//calculate total gpa
		double getGPA();
		//Destructor method
		~Student();
};
#endif