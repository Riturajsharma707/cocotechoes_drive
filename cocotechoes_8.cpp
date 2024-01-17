// **********************************
// **        Question 8            **
// **********************************

#include<bits/stdc++.h>
using namespace std;

struct Subject {
   string name;
   int totalMarks;
   int marksScored;
};

struct Student {
   string name;
   vector<Subject> subjects;
   int totalMarks = 0;
};

Student createStudent(int id) {
   Student student;
   student.name = "Student" + to_string(id);

   vector<string> subjectNames = {"English", "Hindi", "Math 1", "Math 2", "Science"};
   vector<int> totalMarks = {100, 100, 70, 70, 100};

   random_device rd;
   mt19937 generator(rd());

   for (int i = 0; i < 5; i++) {
       Subject subject;
       subject.name = subjectNames[i];
       subject.totalMarks = totalMarks[i];
       uniform_int_distribution<int> distribution(0, totalMarks[i]);
       subject.marksScored = distribution(generator);
       student.subjects.push_back(subject);
       student.totalMarks += subject.marksScored;
   }

   return student;
}

bool compareStudents(const Student& a, const Student& b) {
   return a.totalMarks > b.totalMarks;
}

int main() {
   vector<Student> students;
   
   int fullMarks= 100+100+70+70+100; 
   
   for (int i = 1; i <= 20; i++) {
       students.push_back(createStudent(i));
   }
   
   sort(students.begin(), students.end(), compareStudents);
   
   cout << "Top 5 Students:" << endl;
   cout << "Rank\tName\tTotal Marks\tOut of" << endl;
   for (int i = 0; i < 5; i++) {
       cout << i + 1 << "\t" << students[i].name << "\t" << students[i].totalMarks<<"\t" <<fullMarks <<endl;
   }
   return 0;
}