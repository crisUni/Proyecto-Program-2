#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

// SECTION Variables
struct Personas{
    string nombre;
    string apellido;
	int cedula;
    int telefono;
    string direccion;
    string nacimiento;
	Personas * prx ;
};

struct Tiendas{
    string nombre;
	int numero;
    string direccion;
    int telefono;
	Tiendas * prx ;
};

struct Productos{
	int codigo;
    string desc;
    int peso;
    string volumen;
    int unidad;
    float precio;

	Productos * prx ;
};

Personas *P=NULL; Tiendas *T=NULL; Productos *D=NULL;

//!SECTION

//ANCHOR - Validacion Int
bool IsNumber(string x){
    regex e ("^-?\\d+");
    if (regex_match (x,e)) return true;
    else return false;
};
//ANCHOR - Validacion Float
bool IsFloat(string x){
    regex e ("^-?\\d*\\.?\\d+");
    if (regex_match (x,e)) return true;
    else return false;
};
//ANCHOR - Comparacion String
bool StringAlfabetica(string s1, string s2) {
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    for (int i = 0; i < s1.size() && s2.size(); i++) {
        if (s1[i] == s2[i]) { continue; }
        return s1[i] < s2[i]; }
}
//!SECTION

/// SECTION Agregar
//ANCHOR - Agregar Personas
void AgregarP( Personas **p, string nom, string ap, int ced, int telf, string direc, string nac){
	Personas *ax=new Personas;
	ax->cedula= ced; 
	ax->apellido= ap;
	ax->nombre= nom;
	ax->direccion= direc;
	ax->telefono= telf;
	ax->nacimiento= nac;
	ax->prx= NULL;

	if (*p==NULL){*p= ax;}
	else{ax->prx = *p; *p= ax;}
};
//ANCHOR - Agregar Tiendas
void AgregarT( Tiendas **p, string nom, int num, int telf, string dir ){
	Tiendas *ax=new Tiendas;
	
	ax->nombre = nom;
	ax->numero = num; 
	ax->telefono = telf;
	ax->direccion = dir;
	ax->prx = NULL;

	if (*p==NULL){*p= ax;}
	else{ax->prx = *p; *p = ax;}
};
//ANCHOR - Agregar Productos
void AgregarPr( Productos **p, int cod, string desc, int peso, string vol, int uni, float prec ){
	Productos *ax=new Productos;

	ax->codigo= cod; 
	ax->desc= desc;
	ax->peso= peso;
	ax->volumen= vol;
	ax->unidad= uni;
	ax->precio= prec;
	ax->prx= NULL;

	if (*p==NULL){*p= ax;}
	else{ax->prx = *p; *p= ax;}
};
//!SECTION

//SECTION - Modificar
//ANCHOR - Modificar Personas
int ModificarP(Personas **p){
	string n, a, nom, ap, dir, nac;
	int seleccion, c, tlf;
    Personas *ax = *p;
	cout << "\n \t \t Modificar Personas\n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 1. Por nombre \n";
    cout << "\t 2. Por cedula \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Regresar al menu anterior \n \n";
    cout << "\t Seleccion: "; cin >> seleccion;

	switch(seleccion){
	case 0: return 0;
	case 1:
		cout<<"Indique el nombre de la persona que quiere modificar: "; cin>>n;
		cout<<"Indique el apellido de la persona que quiere modificar: "; cin>>a;
		while (ax) {
           	if ((ax->nombre == n) && (ax->apellido == a)){
				cout<<"Nuevo nombre: "; cin>>nom; ax->nombre = nom;
				cout<<"Nuevo apellido: "; cin>>ap; ax->apellido = ap;
				cout<<"Nueva direccion: "; cin>>dir; ax->direccion = dir;
				cout<<"Nuevo numero de telefono: "; cin>>tlf; ax->telefono = tlf;
				cout<<"Nueva fecha de nacimiento: "; cin>>nac; ax->nacimiento = nac;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ninguna persona con ese nombre.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
	case 2:
		cout<<"Indique la cedula de la persona que se quiere modificar: "; cin>>c;
		while (ax) {
			if (ax->cedula == c){
				cout<<"Nuevo nombre: "; cin>>nom; ax->nombre = nom;
				cout<<"Nuevo apellido: "; cin>>ap; ax->apellido = ap;
				cout<<"Nueva direccion: "; cin>>dir; ax->direccion = dir;
				cout<<"Nuevo numero de telefono: "; cin>>tlf; ax->telefono = tlf;
				cout<<"Nueva fecha de nacimiento: "; cin>>nac; ax->nacimiento = nac;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ninguna persona con esa cedula.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
	} return seleccion;
};
//ANCHOR - Modificar Tiendas
int ModificarT(Tiendas **p){
    Tiendas *ax;
	string mod, nom, dir;
	int seleccion, n, num, tlf;
	cout << "\n \t \t Modificar Tiendas\n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 1. Por nombre \n";
    cout << "\t 2. Por numero \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Regresar al menu anterior \n \n";
    cout << "\t Seleccion: "; cin >> seleccion;

	switch(seleccion){
	case 0: return 0;
	case 1:
		cout<<"Indique el nombre de la tienda que quiere modificar"; cin>>mod;
		while(ax) {
			if (ax->nombre == mod){
				cout<<"Nueva direccion: "; cin>>dir;
				ax->direccion = dir;
				cout<<"Nuevo numero de telefono: "; cin>>tlf;
				ax->telefono = tlf;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ninguna tienda con ese nombre.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
	case 2:
		cout<<"Indique el numero de la tienda que se quiere modificar"; cin>>n;
		while (ax) {
			if (ax->numero == n){
				cout<<"Nuevo nombre: "; cin>>nom; ax->nombre = nom;
				cout<<"Nueva direccion: "; cin>>dir; ax->direccion = dir;
				cout<<"Nuevo numero de telefono: "; cin>>tlf; ax->telefono = tlf;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ninguna tienda con ese numero.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
	} return seleccion;
};
//ANCHOR - Modificar Productos
int ModificarPr(Productos **p){
    Productos *ax;
	string d, des, vol;
	int seleccion, c, cod, pes, un;
	float prec;
	cout << "\n \t \t Modificar Productos\n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 1. Por codigo \n";
    cout << "\t 2. Por descripcion \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Regresar al menu anterior \n \n";
    cout << "\t Seleccion: "; cin >> seleccion;
    
	switch(seleccion){
	case 0: return 0;
	case 1:
		cout<<"Indique el codigo del producto que se quiere modificar"; cin>>c;
		while (ax){
			if (ax->codigo == c) {
				cout << "Nueva descripcion: "; cin>>des; ax->desc = des;
				cout<<"Nuevo peso: "; cin>>pes; ax->peso = pes;
				cout<<"Nuevo volumen: "; cin>>vol; ax->volumen = vol;
				cout<<"Nueva unidad: "; cin>>un; ax->unidad = un;
				cout<<"Nuevo precio: "; cin>>prec; ax->precio = prec;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ningun producto con ese codigo.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
	case 2:
		cout<<"Indique la descripcion del producto que se quiere modificar"; cin>>d;
		while (ax) {
			if (ax->desc == d) {
				cout<<"Nuevo peso: "; cin>>pes; ax->peso = pes;
				cout<<"Nuevo volumen: "; cin>>vol; ax->volumen = vol;
				cout<<"Nueva unidad: "; cin>>un; ax->unidad = un;
				cout<<"Nuevo precio: "; cin>>prec; ax->precio = prec;
				return seleccion;
            } ax = ax->prx; }
        cout << "No se encontro ningun producto con esa descripcion.\n";
        cout << "Presione ENTER para continuar.\n";
        getchar();
        break;
    } return seleccion;
};
//!SECTION

//SECTION - Consultar
//ANCHOR - Consultar Cedula Persona
void ConsultarCedulaP(Personas **p){    
    Personas *ax=*p;
    bool hallado = false; int cedula;
    cout << "Indique la cedula a consultar: "; cin >> cedula;

    while((ax != NULL)&&(!hallado)){
        if(ax->cedula == cedula){
           cout << "Persona encontrada:" << "\n";
           cout << "Nombre de la persona:" << ax->nombre  << "\n";
           cout << "Apellido de la persona:" << ax->apellido << "\n";
           cout << "Direccion de la persona de la persona:" << ax->direccion << "\n";
           cout << "Telefono de la persona:" << ax->telefono << "\n";
           cout << "Nacimiento de la persona:" << ax->nacimiento << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "La cedula consultada no fue encontrada" << "\n";
};
//ANCHOR - Consultar Nombre Persona
void ConsultarNombreP(Personas **p){
    Personas *ax=*p;
    bool hallado = false; string nombre; string apellido;
    cout << "Indique el nombre de la persona a consultar: "; cin >> nombre;
    cout << "Indique el apellido de la persona a consultar: "; cin >> apellido;

    while((ax != NULL)&&(!hallado)){
        if(ax->nombre == nombre && ax->apellido == apellido){
           cout << "Persona encontrada:" << "\n";
           cout << "Nombre de la persona:" << ax->nombre  << "\n";
           cout << "Apellido de la persona:" << ax->apellido << "\n";
           cout << "Direccion de la persona de la persona:" << ax->direccion << "\n";
           cout << "Telefono de la persona:" << ax->telefono << "\n";
           cout << "Nacimiento de la persona:" << ax->nacimiento << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "El nombre y apellido consultados no fueron encontrados" << "\n";
};
//ANCHOR - Consultar Numero Tienda
void ConsultarNumeroT(Tiendas **t){    
    Tiendas *ax=*t;
    bool hallado = false; int numero;
    cout << "Indique el numero de la tienda a consultar: "; cin >> numero;

    while((ax != NULL)&&(!hallado)){
        if(ax->numero == numero){
           cout << "Tienda encontrada:" << "\n";
           cout << "Nombre de la tienda:" << ax->nombre  << "\n";
           cout << "Numero de la tienda:" << ax->numero << "\n";
           cout << "Direccion de la tienda:" << ax->direccion << "\n";
           cout << "Telefono de la tienda:" << ax->telefono << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "El numero consultado no fue encontrado" << "\n";
};
//ANCHOR - Consultar Nombre Tienda
void ConsultarNombreT(Tiendas **t){
    Tiendas *ax=*t;
    bool hallado = false; string nombre;
    cout << "Indique el nombre de la tienda a consultar: "; cin >> nombre;

    while((ax != NULL)&&(!hallado)){
        if (ax->nombre == nombre) {
           cout << "Nombre de la tienda: " << ax->nombre  << "\n";
           cout << "Numero de la tienda: " << ax->numero << "\n";
           cout << "Direccion de la tienda: " << ax->direccion << "\n";
           cout << "Telefono de la tienda: " << ax->telefono << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "El nombre de la tienda no fue encontrado" << "\n";
};
//ANCHOR - Consultar Codigo Producto
void ConsultarCodigoPr(Productos **pr){
    Productos *ax = *pr;
    bool hallado = false; int codigo;
    cout << "Indique el codigo de producto a consultar: "; cin >> codigo;

    while((ax != NULL)&&(!hallado)){
        if (ax->codigo == codigo) {
           cout << "Producto encontrado:" << "\n";
           cout << "Codigo del producto:" << ax->codigo  << "\n";
           cout << "Descripcion del producto:" << ax->desc  << "\n";
           cout << "Peso del producto:" << ax->peso  << "\n";
           cout << "Volumen del producto:" << ax->volumen  << "\n";
           cout << "Unidades del producto:" << ax->unidad  << "\n";
           cout << "Precio del producto:" << ax->precio  << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "El codigo del producto no fue encontrado" << "\n";
};
//ANCHOR - Consultar Descripcion Producto
void ConsultarDescripcionPr(Productos **pr){
    Productos *ax = *pr;
    bool hallado = false; string descripcion;
    cout << "Indique la descripcion del producto a consultar: "; cin >> descripcion;

    while((ax != NULL)&&(!hallado)){
        if (ax->desc == descripcion) {
           cout << "Producto encontrado:" << "\n";
           cout << "Codigo del producto:" << ax->codigo  << "\n";
           cout << "Descripcion del producto:" << ax->desc  << "\n";
           cout << "Peso del producto:" << ax->peso  << "\n";
           cout << "Volumen del producto:" << ax->volumen  << "\n";
           cout << "Unidades del producto:" << ax->unidad  << "\n";
           cout << "Precio del producto:" << ax->precio  << "\n";
           hallado = true;
        } ax=ax->prx;
    }
    if(!hallado)
       cout << "La descripcion no fue encontrada" << "\n";
};
//!SECTION

//SECTION - Eliminar
//ANCHOR - Eliminar Personas
void EliminarP(Personas **p){
    Personas *ax= *p,*t;
    int buscarCedula; bool found;
    cout << "Indique la cedula de la persona que se desea eliminar del sistema: "; cin >> buscarCedula;
    
    if(ax->cedula==buscarCedula){*p=ax->prx; delete ax;}
    while (ax->prx && !found){
        if ((ax->prx)->cedula==buscarCedula){
            t=ax->prx;
            ax->prx=ax->prx->prx;
            delete t;
            found = true;
        };
        ax=ax->prx;
    }
};
//ANCHOR - Eliminar Tiendas
void EliminarT(Tiendas **p){
    Tiendas *ax= *p,*t;
    int buscarTienda; bool found;
    cout << "Indique el numero de la tienda que se desea eliminar del sistema: "; cin >> buscarTienda;

    if(ax->numero==buscarTienda){*p=ax->prx; delete ax; }
    while (ax->prx && !found){
        if ((ax->prx)->numero==buscarTienda){
            t=ax->prx;
            ax->prx=ax->prx->prx;
            delete t;
            found = true;
        }
        ax=ax->prx;
    }
};
//ANCHOR - Eliminar Productos
void EliminarPr(Productos **p){
    Productos *ax= *p,*t;
    int buscarProducto; bool found;
    cout << "Indique el codigo del producto que se desea eliminar del sistema: "; cin >> buscarProducto;
    
    if(ax->codigo ==buscarProducto){*p=ax->prx; delete ax; }
    while (ax->prx && !found){
        if ((ax->prx)->codigo==buscarProducto){
            t=ax->prx;
            ax->prx=ax->prx->prx;
            delete t;
            found = true;
        }
        ax=ax->prx;
    }
};
//!SECTION

//SECTION - Mostrar
//ANCHOR - Mostrar Personas
void MostrarP(Personas *p){
    Personas *ax = p;
    while (ax != NULL){
        cout << ax->nombre << ", " << ax->apellido << " " << ax->cedula 
             << " " << ax->telefono << " " << ax->direccion << " " << ax->nacimiento << "\n";
        ax=ax->prx;
    }
}
//ANCHOR - Mostrar Tiendas
void MostrarT(Tiendas *p){
    Tiendas *ax = p;
    while (ax != NULL){
        cout << ax->nombre << ". " << ax->numero << " " << ax->telefono << " " << ax->direccion << "\n";
        ax=ax->prx;
    }
}
//ANCHOR - Mostrar Productos
void MostrarPr(Productos *p){
    Productos *ax = p;
    while (ax != NULL){
        cout << ax->codigo << ", " << ax->desc << " " << ax->peso 
             << "kg " << ax->volumen << " " << ax->unidad << " " << ax->precio << "$\n";
        ax=ax->prx;
    }
}
//!SECTION

//SECTION - Ordenar 
//ANCHOR - Ordenar Numero Personas
void OrdenarNumP( Personas **p ){
    if ((*p == NULL) || ((*p)->prx == NULL)) { return; }
    Personas *ax = *p; Personas *bx = ax; int ci,tel; string nom, ape, dir, nace;
    bx = bx->prx;
    while (ax->prx != NULL) {
        while (bx != NULL) {
            if (ax->cedula > bx->cedula) {
                nom = bx->nombre; ape = bx->apellido; ci = bx->cedula; tel = bx->telefono; dir = bx->direccion; nace = bx->nacimiento;
                bx->nombre = ax->nombre; bx->apellido = ax->apellido; bx->cedula = ax->cedula; 
                bx->telefono = ax->telefono; bx->direccion = ax->direccion; bx->nacimiento = ax->nacimiento;
                ax->nombre = nom; ax->apellido=ape; ax->telefono=tel; ax->direccion=dir; ax->nacimiento=nace; ax->cedula=ci;
            } bx = bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//ANCHOR - Ordenar Nombre Persona
void OrdenarNomP( Personas **p ){
    if ((*p == NULL) || ((*p)->prx == NULL)) { return; }
    Personas *ax = *p; Personas *bx = ax; int ci,tel; string nom, ape, dir, nace;
    bx = bx->prx;
    while (ax->prx != NULL) {
        while (bx != NULL) {
            if (StringAlfabetica(bx->nombre, ax->nombre) || (ax->nombre == bx->nombre && StringAlfabetica(bx->apellido, ax->apellido))) {
                nom = bx->nombre; ape = bx->apellido; ci = bx->cedula; tel = bx->telefono; dir = bx->direccion; nace = bx->nacimiento;
                bx->nombre = ax->nombre; bx->apellido = ax->apellido; bx->cedula = ax->cedula; 
                bx->telefono = ax->telefono; bx->direccion = ax->direccion; bx->nacimiento = ax->nacimiento;
                ax->nombre = nom; ax->apellido=ape; ax->telefono=tel; ax->direccion=dir; ax->nacimiento=nace; ax->cedula=ci;
            } bx = bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//ANCHOR - Ordenar Numero Tienda
void OrdenarNumT( Tiendas **t ){
    if ((*t == NULL) || ((*t)->prx == NULL)) { return; }
    Tiendas *ax = *t; Tiendas *bx = ax; int num,tel; string nom, ape, dir, nace;
    while (ax->prx != NULL) {
        while (bx !=NULL) {
            if (ax->numero > bx->numero){
                nom = bx->nombre; num = bx->numero; tel = bx->telefono; dir = bx->direccion; 
                bx->nombre = ax->nombre; bx->numero = ax->numero; bx->telefono = ax->telefono; bx->direccion = ax->direccion;
                ax->nombre = nom; ax->numero=num; ax->telefono=tel; ax->direccion=dir;
            } bx=bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//ANCHOR - Ordenar Nombre Persona
void OrdenarNomT( Tiendas **t ){
    if ((*t == NULL) || ((*t)->prx == NULL)) { return; }
    Tiendas *ax = *t; Tiendas *bx = ax; int num,tel; string nom, ape, dir, nace;
    bx = bx->prx;
    while (ax->prx != NULL) {
        while (bx != NULL) {
            if (StringAlfabetica(bx->nombre, ax->nombre)) {
                nom = bx->nombre; num = bx->numero; tel = bx->telefono; dir = bx->direccion;
                bx->nombre = ax->nombre; bx->numero = ax->numero; bx->telefono = ax->telefono; bx->direccion = ax->direccion;
                ax->nombre = nom; ax->numero = num; ax->telefono = tel; ax->direccion = dir;
            } bx = bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//ANCHOR - Ordenar Numero Producto
void OrdenarNumPr( Productos **p ){
    if ((*p == NULL) || ((*p)->prx == NULL)) { return; }
    Productos *ax = *p; Productos *bx = ax; int num,tel,peso,uni; string nom, ape, dir, nace; float price;
    bx = bx->prx;
    while (ax->prx != NULL) {
        while (bx != NULL) {
            if (ax->codigo < bx->codigo){
                num = bx->codigo; nom = bx->desc; peso = bx->peso; dir = bx->volumen; uni=bx->unidad; price=bx->precio;
                bx->codigo = ax->codigo; bx->desc = ax->desc;  bx->peso = ax->peso; 
                bx->volumen = ax->volumen; bx->unidad = ax->unidad; bx->precio = ax->precio;
                ax->codigo=num; ax->desc = nom; ax->peso=peso; ax->volumen=dir; ax->precio=price;
            } bx=bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//ANCHOR - Ordenar Descripcion Producto
void OrdenarDescPr( Productos **p ) {
    if ((*p == NULL) || ((*p)->prx == NULL)) { return; }
    Productos *ax = *p; Productos *bx = ax; int num,tel,peso,uni; string nom, ape, dir, nace; float price;
    bx = bx->prx;
    while (ax->prx != NULL) {
        while (bx != NULL) {
            if (StringAlfabetica(bx->desc, ax->desc)) {
                num = bx->codigo; nom = bx->desc; peso = bx->peso; dir = bx->volumen; uni=bx->unidad; price=bx->precio;
                bx->codigo = ax->codigo; bx->desc = ax->desc;  bx->peso = ax->peso; 
                bx->volumen = ax->volumen; bx->unidad = ax->unidad; bx->precio = ax->precio;
                ax->codigo=num; ax->desc = nom; ax->peso=peso; ax->volumen=dir; ax->precio=price;
            } bx=bx->prx;
        } ax = ax->prx; bx = ax->prx;
    }
};
//!SECTION

//SECTION Archivos
//ANCHOR - Crear Personas
void CrearArchivoP( Personas *p) {
    Personas *ax = p; 
    ofstream MyFile("Personas.txt");

    MyFile << "SISTEMA CONTROL DE VENTAS\n";
    MyFile << "Personas";

    while (ax){
        MyFile << "\n" << ax->nombre << "\n";
        MyFile << ax->apellido << "\n";
        MyFile << ax->cedula << "\n";
        MyFile << ax->telefono << "\n";
        MyFile << ax->direccion << "\n";
        MyFile << ax->nacimiento << "\n";
        MyFile << ".";
        ax=ax->prx;
    }
    
    MyFile.close();

};
//ANCHOR - Crear Tiendas
void CrearArchivoT( Tiendas *p){
    Tiendas *ax= p; 
    ofstream MyFile("Tiendas.txt");

    MyFile << "SISTEMA CONTROL DE VENTAS\n";
    MyFile << "Tiendas";

    while (ax) {
        MyFile << "\n" <<ax->nombre << "\n";
        MyFile << ax->numero << "\n";
        MyFile << ax->direccion << "\n";
        MyFile << ax->telefono << "\n";
        MyFile << "." ;
        ax = ax->prx;
    }
    
    MyFile.close();

};
//ANCHOR - Crear Productos
void CrearArchivoPr( Productos *p){
    Productos *ax= p; 
    ofstream MyFile("Productos.txt");

    MyFile << "SISTEMA CONTROL DE VENTAS\n";
    MyFile << "Productos\n";

    while (ax){
        MyFile << ax->codigo << "\n";
        MyFile << ax->desc << "\n";
        MyFile << ax->peso << "\n";
        MyFile << ax->volumen << "\n";
        MyFile << ax->unidad << "\n";
        MyFile << ax->precio << "\n";
        MyFile << "." << "\n";
        ax = ax->prx;
    }
    
    MyFile.close();

};
//ANCHOR - Leer Personas
int LeerArchivoP(Personas **p, string path = "Personas.txt"){
    string text, nom, ape, dir, nace; int ci, telf; 
    int c=1;
    fstream File;
    File.open(path, ios::in);
    if (!File) { cout << "El archivo dado no existe\n"; return 1;}
    getline(File, text); 
    if (text != "SISTEMA CONTROL DE VENTAS"){ cout << "El archivo no es el adecuado\n"; return 1; }
    getline(File, text); 
    if (text != "Personas"){ cout << "El archivo no es tipo persona\n"; return 1; }

    while (!File.eof()) {
        nom = ""; ape = ""; dir = ""; nace = "";
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            nom = text;
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            ape = text;
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            ci = stoi(text);
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            telf = stoi(text); 
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            dir = text;
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            nace = text;
        getline(File,text); if(text != "."){
            do {
                getline(File,text);
            } while (text!="."); 
        }
        AgregarP(p, nom, ape, ci, telf, dir,nace);
        c++;
    }
    File.close(); 
    cout << "El archivo fue leido exitosamente! \n \n";
    return 0;
};
//ANCHOR - Leer Tiendas
int LeerArchivoT(Tiendas **t, string path = "Tiendas.txt"){
    string text, nom, ape, dir, nace; int num, telf; 
    int c=1;
    fstream File;
    File.open(path, ios::in);
    if (!File) {cout << "El archivo dado no existe\n"; return 1;}
    getline(File, text); 
    if (text != "SISTEMA CONTROL DE VENTAS"){cout << "El archivo no es el adecuado\n"; return 1; }
    getline(File, text); 
    if (text != "Tiendas"){cout << "El archivo no es tipo tiendas\n"; return 1; }

    while (!File.eof()) {
        nom = ""; num = 0; dir = ""; 
       
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            nom = text;
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            num = stoi(text);
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            telf = stoi(text);
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            dir = text;
        getline(File,text); if(text != "."){
            do {
                getline(File,text);
            } while (text!="."); 
        }
        AgregarT(t, nom, num, telf, dir);
        c++;
    }
    File.close(); 
    cout << "El archivo fue leido exitosamente! \n \n";
    return 0;
};
//ANCHOR - Leer Productos
int LeerArchivoPr(Productos **pr, string path = "Productos.txt"){
    string text, desc, vol, dir, nace; int cod, peso, uni; float perc;
    int c=1;
    fstream File;
    File.open(path, ios::in);
    if (!File) { cout << "El archivo dado no existe\n"; return 1;}
    getline(File, text); 
    if (text != "SISTEMA CONTROL DE VENTAS"){ cout << "El archivo no es el adecuado\n"; return 1; }
    getline(File, text); 
    if (text != "Productos"){ cout << "El archivo no es tipo producto\n"; return 1; }

    while (!File.eof()) {
        desc = ""; cod = 0; vol = ""; nace = ""; uni = 0;
       
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            cod = stoi(text);
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            desc = text;
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            peso = stoi(text);
        getline(File,text); if (IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            vol = text;
        getline(File,text); if (!IsNumber(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            uni = stoi(text);
        getline(File,text); if (!IsFloat(text) || (text == ".")){
            cout << "El elemento "<< c <<" posee valores invalidos, saltando\n";
            continue;}; 
            perc = stoi(text);

        getline(File,text); if(text != "."){
            do {
                getline(File,text);
            } while (text!="."); 
        }
        AgregarPr(pr, cod, desc, peso, vol, uni, perc);
        c++;
    }
    File.close(); 
    cout << "El archivo fue leido exitosamente! \n \n";
    return 0;
};
//!SECTION

//SECTION MENUS
//ANCHOR - Menu Mod
int MenuMod(int type){
    string name; int sel; string c1, c2;
    switch (type){
    case 1: name = "Personas"; c1 ="cedula"; c2 ="nombre";break;
    case 2: name = "Productos"; c1 ="numero de tienda"; c2 ="nombre"; break;
    case 3: name = "Tiendas"; c1 ="codigo"; c2 ="descripcion"; break;
    default: name = "Code Error"; break; }

    int seleccion = 0;
    cout << "\n \t \t Mantenimiento de " << name << " \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 1" << type << "1. Agregar \n";
    cout << "\t 1" << type << "2. Modificar \n";
    cout << "\t 1" << type << "3. Consultar por "<< c1 << "\n";
    cout << "\t 1" << type << "4. Consultar por "<< c2 << "\n";
    cout << "\t 1" << type << "5. Mostrar todos ordenados por "<< c1 << "\n";
    cout << "\t 1" << type << "6. Mostrar todos ordenados por "<< c2 << "\n";
    cout << "\t 1" << type << "7. Eliminar \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Volver al menu anterior \n \n";
    cout << "\t Seleccion: ";
    cin >> seleccion;     

    switch(seleccion){
        case 0:
            return 0;        
        case 1:
            system("cls");
            if (type==1){
                    int ci, telf; string ap, nom, dir, nac;
                	cout<<"Nombres: "; cin >> nom;
                    cout<<"Apellidos: "; cin >> ap;
                    cout<<"Numero de cedula: "; cin >> ci;
                    cout<<"Numero de telefono: "; cin >> telf;
                    cout<<"Direccion: "; cin >> dir;
                    cout<<"Fecha de nacimiento: "; cin >> nac;             
                AgregarP(&P, nom, ap, ci, telf, dir, nac);
            }
            if (type==2) {
                int num,telf; string nom, dir;
                cout<<"Nombre de la tienda: "; cin>>nom;
                cout<<"Numero de tienda: "; cin>>num;
                cout<<"Numero de telefono de la tienda: "; cin>>telf;
                cout<<"Direccion de la tienda: "; cin>>dir;
                AgregarT(&T, nom, num, telf, dir);
            };
            if (type==3){
                int cod, pes, uni; float prec; string des, vol; 
                cout<<"Codigo del producto: ";
                cin>>cod;
                cout<<"Descripcion del producto: ";
                cin>>des;
                cout<<"Peso del producto: ";
                cin>>pes;
                cout<<"Volumen del producto: ";
                cin>>vol;
                cout<<"Unidad (Kgr o Ltr): ";
                cin>>uni;
                cout<<"Precio";
                cin>>prec;
                AgregarPr(&D, cod, des, pes, vol, uni, prec);
            };
            break;
        case 2:
            system("cls");
            if (type==1){ do {sel = ModificarP(&P); } while (sel!=0);}
            if (type==2){ do {sel = ModificarT(&T); } while (sel!=0);}
            if (type==3){ do {sel = ModificarPr(&D); } while (sel!=0);}            
            break;
        case 3:
            system("cls");
            if (type==1){ ConsultarCedulaP(&P);}
            if (type==2){ ConsultarNumeroT(&T);}
            if (type==3){ ConsultarCodigoPr(&D);}
            break;
        case 4:
            system("cls");
            if (type==1){ ConsultarNombreP(&P);}
            if (type==2){ ConsultarNombreT(&T);}
            if (type==3){ ConsultarDescripcionPr(&D);}
            break;
        case 5:
            system("cls");
            if (type==1){ OrdenarNumP(&P); MostrarP(P);}
            if (type==2){ OrdenarNumT(&T); MostrarT(T);}
            if (type==3){ OrdenarNumPr(&D); MostrarPr(D);}
            break;
        case 6:
            system("cls");
            if (type==1){ OrdenarNomP(&P); MostrarP(P);}
            if (type==2){ OrdenarNomT(&T); MostrarT(T);}
            if (type==3){ OrdenarDescPr(&D); MostrarPr(D);}
            break;
        case 7:
            system("cls");
            if (type==1){ EliminarP(&P);}
            if (type==2){ EliminarT(&T);}
            if (type==3){ EliminarPr(&D);}
            break;
        default:
            system("cls");
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    }
    return seleccion;
};

//ANCHOR - Menu Reporte
int MenuReporte(){return 0;};

//ANCHOR - Mantenimiento
int MenuMantenimiento(){
    int seleccion = 0; int sel;
    cout << "\n \t \t MENU DE MANTENIMIENTO \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 11. Personas \n";
    cout << "\t 12. Tiendas \n";
    cout << "\t 13. Productos \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Volver al menu anterior \n \n";
    cout << "\t Seleccion: ";
    cin >> seleccion;     

    switch(seleccion){
        case 0:
            return 0;
        case 1:
            system("cls");
            do {sel =  MenuMod(1); } while (sel!=0);
            break;
        case 2:
            system("cls");
            do {sel =  MenuMod(2); } while (sel!=0);
            break;
        case 3:
            system("cls");
            do {sel =  MenuMod(3); } while (sel!=0);
            break;
        default:
            system("cls");
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    }
    system("cls");
    return seleccion;
};

int MenuCargarDir(){
    int seleccion = 0;
    cout << "\t \t Indique el archivo que quiere cargar: \n";
    cout << "======================================================= \n \n";
    cout << "\t 1. Personas: \n";
    cout << "\t 2. Tiendas: \n";
    cout << "\t 3. Producto: \n\n";
    cout << "======================================================= \n \n";
    cout << "\t 0. Regresar al menu anterior \n\n";
    cout << "\t Seleccion: ";
    cin >> seleccion;
    if (seleccion > 0 && seleccion < 4) {
        cout << "\t \nIndique la direccion del archivo de ";
        switch(seleccion) {
            case 1: cout << "Personas: "; break;
            case 2: cout << "Tiendas: "; break;
            case 3: cout << "Productos: "; break;
        } cout << "\n";
        string input; cin >> input;
        switch(seleccion) {
            case 1: cout << LeerArchivoP(&P, input); break;
            case 2: cout << LeerArchivoT(&T, input); break;
            case 3: cout << LeerArchivoPr(&D, input); break;
        }
    } return 0;
}

//ANCHOR - Menu Guardar
int MenuGuardar(){
    int seleccion = 0;
    cout << "\t \t Indique el archivo que desea guardar \n";
    cout << "======================================================= \n \n";
    cout << "\t 1. Personas \n";
    cout << "\t 2. Tiendas \n";
    cout << "\t 3. Productos \n\n";
    cout << "======================================================= \n \n";
    cout << "\t 0. Regresar al menu anterior \n\n";
    cout << "\t Seleccion: ";
    cin >> seleccion;
    switch(seleccion){
        case 0:
            return 0;
        case 1:
            system("cls");
            CrearArchivoP(P);
            cout << "El archivo fue guardado exitosamente! \n \n";
            break;
        case 2:
            system("cls");
            CrearArchivoT(T);
            cout << "El archivo fue guardado exitosamente! \n \n";
            break;
        case 3:
            system("cls");
            CrearArchivoPr(D);
            cout << "El archivo fue guardado exitosamente! \n \n";
            break;
        default:
            system("cls");
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    }
    return seleccion;
};
//ANCHOR - Cargar dir
int MenuCargar(){
    int seleccion = 0;
    cout << "\t \t Indique el archivo que desea cargar \n \n";
    cout << "\t =====================================\n \n";
    cout << "\t 1. Personas \n";
    cout << "\t 2. Tiendas \n";
    cout << "\t 3. Productos \n \n";
    cout << "\t ===================================== \n \n";
    cout << "\t 0. Regresar al menu anterior\n \n";
    cout << "\t Seleccion: ";
    cin >> seleccion;
    switch(seleccion){
        case 0:
            return 0;
        case 1:
            system("cls");
            LeerArchivoP(&P);
            break;
        case 2:
            system("cls");
            LeerArchivoT(&T);
            break;
        case 3:
            system("cls");
            LeerArchivoPr(&D);
            break;
        default:
            system("cls");
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    }
    return seleccion;
};

//ANCHOR - Menu Sistema
int MenuSistema(){
    int seleccion = 0; int sel = 0;
    cout << "\n \t \t Menu de Sistema \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 21. Guardar \n";
    cout << "\t 22. Cargar Archivo en el direcctorio actual\n";
    cout << "\t 23. Cargar Archivo de otra ubicacion \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Volver al menu anterior \n \n";
    cout << "\t Seleccion: ";
    cin >> seleccion; 

    switch(seleccion){
        case 0:
            return 0;
        case 1:
            system("cls");
            do {sel = MenuGuardar(); } while (sel!=0);
            break;
        case 2:
            system("cls");
            do {sel =  MenuCargar(); } while (sel!=0);
            break;
        case 3:
            system("cls");
            do {sel =  MenuCargarDir(); } while (sel!=0);
            break;
        default:
            system("cls");
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    }
    return seleccion;
    return 0;
};

//ANCHOR - Menu Principal
int MenuPrincipal(){
    int seleccion = 0; int sel;
    cout << "\n \t \t MENU PRINCIPAL \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 1. Mantenimiento \n";
    cout << "\t 2. Sistema \n";
    cout << "\t 3. Reporte \n \n";
    cout << "------------------------------------------------------- \n \n";
    cout << "\t 0. Salir \n \n";
    cout << "\t Seleccion: ";
    cin >> seleccion; 

    switch(seleccion){
        case 0:
            return 0;
        case 1:
            system("cls");
            do {sel = MenuMantenimiento(); } while (sel!=0);
            break;
        case 2:
            system("cls");
            do {sel = MenuSistema(); } while (sel!=0);
            break;
        case 3:
            system("cls");
            break;
        default:
            cout << "\n \t ERROR: Esa no es una opcion. Porfavor vuelva a intentar \n \n";
            cin;
    } 
    system("cls");
    return seleccion;
};

//!SECTION

int main(){

    int seleccion;
    system("cls");
    do { seleccion = MenuPrincipal(); } while (seleccion!=0);

    return 0;
}