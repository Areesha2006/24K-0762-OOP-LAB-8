#include<iostream>
using namespace std;
class Teacher;
class Student{
    string name;
    int grades[3];
    friend class Teacher;
    friend float calculateAverageGrade(Student s);
    public:
        Student(string name,int grade[]){
            this->name=name;
            for(int i=0;i<3;i++){
                grades[i]=grade[i];
            }
        }
};
class Teacher{
    public:
        void view_grades(Student s){
            for(int i=0;i<3;i++){
                cout<<"Grade for subject "<<i+1<<": "<<s.grades[i]<<endl;
            }
        }
        void update_grade(Student &s){
            int subject;
            cout<<"Enter the subject number whose grade you want to update (1-3): ";
            cin>>subject;
            while(subject>3||subject<1){
                cout<<"Invalid input. Subject number must be in the range (1-3).\nEnter again: ";
                cin>>subject;
            }
            cout<<"Enter updated grade: ";
            cin>>s.grades[subject-1];
        }
};
float calculateAverageGrade(Student s){
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=s.grades[i];
    }
    return sum/3.0;
}
int main(){
    int grades[3];
    string name;
    cout<<"Enter student name: ";
    cin>>name;
    for(int i=0;i<3;i++){
        cout<<"Enter grade for subject "<<i+1<<": ";
        cin>>grades[i];
    }
    Student student(name,grades);
    Teacher teacher;
    cout<<endl<<"Displaying grades of student"<<endl;
    teacher.view_grades(student);
    cout<<"Average grade: "<<calculateAverageGrade(student);
    cout<<endl;
    teacher.update_grade(student);
    cout<<endl<<"Displaying updated grade details"<<endl;
    teacher.view_grades(student);
    cout<<"Average grade: "<<calculateAverageGrade(student);
    return 0;
}