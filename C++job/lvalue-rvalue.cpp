#include<iostream>
#include <stdio.h>
#include <string.h>

class String {
    private:
        char* m_data;
        uint32_t m_size;
    public:
        String() {
            printf("default constructed \n");
        }
        String(const char* str) {
            printf("overloaded constructed \n");
            m_size = strlen(str);
            m_data = new char[m_size];
            memcpy(m_data, str, m_size);
        }

        String(const String& other) {
            printf("copied \n");
            m_size = other.m_size;
            m_data = new char[m_size];
            memcpy(m_data, other.m_data, m_size);
        }

        String(String&& other) {
            printf("moved \n");
            m_size = other.m_size;
            m_data = other.m_data;
            
            other.m_size = 0;
            other.m_data = nullptr;
        }

        String& operator=(String&& other) {
            printf("assigned \n");

            if(this != &other) {
                delete[] m_data;
                m_size = other.m_size;
                m_data = other.m_data;
                
                other.m_size = 0;
                other.m_data = nullptr;
            }
            return *this;
        }

        ~String(){
            printf("destructed \n");
            delete m_data;
        }

        void print(){
            for (uint32_t i =0; i < m_size; i++) {
                printf("%c",m_data[i]); 
            }
            printf("\n");
        }
};

class Entity {
    public:
        Entity(const String& name): m_name(name){}

        Entity(String&& name): m_name((String&&)name){}
        void print_name() {
            m_name.print();
        }
    private:
        String m_name;
};

int main() {
    // std::cout << "sample program" << std::endl;
    // Entity* entity = new Entity(String("dheeraj"));
    
    String last_name = String("koshti");
    String last_name2;
    printf("last_name before move");
    last_name.print();
    printf("last_name2 before move");
    last_name2.print();

    last_name2 = std::move(last_name);

    printf("last_name after move");
    last_name.print();
    printf("last_name2 after move");
    last_name2.print();

    return 1;
}