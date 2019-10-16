#include <iostream>
#include <cmath>


using namespace std;

#define c_uw 25 // constant weight of reinforced concrete beam

#define plm 0.6 // permanent load margin

#define vlm 0.2 // variable load margin

int main(){
    
    double l, h, b, gk, qk, V, M, tcl, ws, wd;
    
     int n = 1;
    
    bool clear = true;
    
    while (n == 1) {
        
        do {
        cout << "This software designs a rectangular beam. Enter the beam specifications:" << endl;
        
        cout << "Enter the length of the beam(m): " ;
        cin >> l ; // Length of beam
            
            if (l <=0){
                clear = false;
                cout << "Enter a positive integer for the length" << endl;
                cout << endl;
                continue;
            }
            
            else{
                clear = true;
            }
            
        cout << "Enter the permanent load(kN/m): " ;
        cin >> gk; // Permanent load
        
            if (gk <=0){
                clear = false;
                cout << "Enter a positive integer for the permanent load" << endl;
                cout << endl;
                continue;
            }
            
            else{
                clear = true;
            }
            
        cout << "Enter the variable load(kN/m): "  ;
        cin >> qk; // Variable load
            
            if (qk <=0){
                clear = false;
                cout << "Enter a positive integer for the variable load" << endl;
                cout << endl;
                continue;
            }
            
            else{
                clear = true;
            }
            
        }
        while (clear == false);
        
        cout << endl;
        h = l/14 * 1000; // depth of beam(h) in mm

        b = h * 0.4 ; // width of beam(b) in mm
        
        ws = h/1000 * b/1000 * c_uw ; // beam self-weight
        
        tcl = ws + gk; // total characteristic permanent action
        
        wd = (1 + plm)*gk + (1 + vlm)*qk ; //Design action
        
        V = wd*l*0.5 ; // shear force
      
        M  = wd * pow(l,2) * 1/8 ; //bending moment
        
        
        cout << "Here is a summary of the beam design: " << endl << endl;
        
        cout << "The minimum values for the size of the beam are: " << endl;
        
        cout << "Depth = " << ceil(h) << " mm, " << "Width = " << ceil(b) << " mm" << endl;
        
        cout << "The total characteristic load = " << tcl << " kN/m" << endl;
        
        cout << "Shear force = " << V << " kN" << endl;
        
        cout << "Bending moment = " << M << " kNm" << endl;
        
        
        cout << "Enter 1 to repeat or any other number to exit: " << endl;
        
        cin >> n;
        
        cout << endl;
        
        
    }
    
    cout << "Program terminating..." << endl;
    
    
}
