#define PY_SSIZE_T_CLEAN
#include <Python.h>

typedef struct Point{

    double x,xprec,y,yprec,m,r;
    int colorR,colorG,colorB,_id;

}Point;

typedef struct Liste{
    double* Tableau;
    int Taille;
}Liste;

PyObject* print_hello_world(PyObject* self, PyObject* args){
    printf("hello, python module's world\n");
    return Py_None;
}
PyObject* Somme_debilus(PyObject* self, PyObject* args){
    int premier_truc;
    int deuxième_machin;
    int somme;
    if (!PyArg_ParseTuple(args,"ii", &premier_truc, &deuxième_machin))
        return NULL;
    somme = premier_truc + deuxième_machin ;
    return Py_BuildValue("i", somme);
}
PyObject* Somme(PyObject* self, PyObject* args){
    double premier_truc;
    double deuxième_machin;
    double somme;
    if (!PyArg_ParseTuple(args,"dd", &premier_truc, &deuxième_machin))
        return NULL;
    somme = premier_truc + deuxième_machin ;
    return Py_BuildValue("d", somme);
}
PyObject* somme_liste(PyObject* self, PyObject* args){
    PyObject *liste_un;
    PyObject *liste_deux;
    if (!PyArg_ParseTuple(args,"OO", &liste_un, &liste_deux))
        return NULL;
    if (PyList_GET_SIZE(liste_un) != PyList_GET_SIZE(liste_deux))
        return NULL;
    PyObject *result = PyList_New(PyList_GET_SIZE(liste_un)) ;
    double temp1;
    double temp2;
    PyObject *Affectation;
    for (int i = 0 ; i< PyList_GET_SIZE(liste_un); i++)
    {
        temp1 = PyFloat_AsDouble(PyList_GetItem(liste_un, i ));
        temp2 = PyFloat_AsDouble(PyList_GetItem(liste_deux, i ));
        Affectation = PyFloat_FromDouble(temp1+temp2);
        PyList_SetItem(result,i, Affectation);
    }

    return(result) ;
}

PyObject* diff_liste(PyObject* self, PyObject* args){
    PyObject *liste_un;
    PyObject *liste_deux;
    if (!PyArg_ParseTuple(args,"OO", &liste_un, &liste_deux))
        return NULL;
    if (PyList_GET_SIZE(liste_un) != PyList_GET_SIZE(liste_deux))
        return NULL;
    PyObject *result = PyList_New(PyList_GET_SIZE(liste_un)) ;
    double temp1;
    double temp2;
    PyObject *Affectation;
    for (int i = 0 ; i< PyList_GET_SIZE(liste_un); i++)
    {
        temp1 = PyFloat_AsDouble(PyList_GetItem(liste_un, i ));
        temp2 = PyFloat_AsDouble(PyList_GetItem(liste_deux, i ));
        Affectation = PyFloat_FromDouble(temp1-temp2);
        PyList_SetItem(result,i, Affectation);
    }

    return(result) ;
}
PyObject* agrandissement(PyObject* self, PyObject* args){
    PyObject *liste;
    double facteur;
    if (!PyArg_ParseTuple(args,"Od", &liste, &facteur))
        return NULL;
    //printf("le facteur est %f",facteur);
    PyObject *result = PyList_New(PyList_GET_SIZE(liste)) ;
    double temp1;
    PyObject *Affectation;
    for (int i = 0 ; i< PyList_GET_SIZE(liste); i++)
    {
        temp1 = PyFloat_AsDouble(PyList_GetItem(liste, i ));
        Affectation = PyFloat_FromDouble(temp1 * facteur);
        PyList_SetItem(result,i, Affectation);
    }
    return(result);
}

double DoubleFromPoint(PyObject *Point, const char *NOM )
{
    PyObject *Recup;
    double result;
    Recup = PyObject_GetAttrString(Point,NOM);
    result = PyFloat_AsDouble(Recup);
    return(result);
}

int IntergerFromPoint(PyObject *Point, const char *NOM )
{
    PyObject *Recup;
    int result;
    Recup = PyObject_GetAttrString(Point,NOM);
    result = PyLong_AsLong(Recup);
    return(result);
}


void PrintPoint(Point pts){
    printf("Tous les doubles: \n x = %f \n, xprec = %f \n, y = %f \n, yprec = %f \n, m = %f \n, r = %f \n",pts.x,pts.xprec,pts.y,pts.yprec,pts.m,pts.r);
    printf("Tous les integers: \n colorR = %i \n, colorG = %i \n, colorB = %i \n, _id = %i \n",pts.colorR,pts.colorG,pts.colorB,pts._id);
}

//<================================================================================================================
//Partie interface avec Point python 
//<================================================================================================================


//PyObject* Decodage(PyObject* self, PyObject* args){
Point Decodage(PyObject* Point_Py)
{
    //Avec l'aide de Mr Tanguy HUMBERT
    Point pts;
    //PyObject *Point;
    //if (!PyArg_ParseTuple(args,"O", &Point))
        //return NULL;
    
    pts.x = DoubleFromPoint(Point_Py,"x");
    pts.xprec = DoubleFromPoint(Point_Py,"xprec");
    pts.y = DoubleFromPoint(Point_Py,"y");
    pts.yprec = DoubleFromPoint(Point_Py,"yprec");
    pts.m = DoubleFromPoint(Point_Py,"m");
    pts.r = DoubleFromPoint(Point_Py,"r");

    pts.colorR = IntergerFromPoint(Point_Py,"colorR");
    pts.colorG = IntergerFromPoint(Point_Py,"colorG");
    pts.colorB = IntergerFromPoint(Point_Py,"colorB");
    pts._id = IntergerFromPoint(Point_Py,"_id");

    PrintPoint(pts);
    return(pts);
}

PyObject* Recodage(Point pts)
{ 
    PyObject *Attributs = PyImport_AddModule("__main__");
    PyObject *Format = PyObject_GetAttrString(Attributs,"Point");

    PyObject *Valeurs = Py_BuildValue("ddddddiiii",pts.x,pts.xprec,pts.y,pts.yprec,pts.m,pts.r,pts.colorR,pts.colorG,pts.colorB,pts._id);
    PyObject *Objet = PyObject_CallObject(Format,Valeurs);
    
    Py_DECREF(Valeurs);
    Py_DECREF(Format);

    return(Objet);

}

PyObject* Test_Verlet(PyObject* self, PyObject* args)
{
    PyObject *Point_Py;
    if (!PyArg_ParseTuple(args,"O", &Point_Py))
    {
        return NULL ;
    }
    Point pts = Decodage(Point_Py);

    PyObject *Sortie = Recodage(pts);

    printf("On a passé le recodage \n");

    return(Sortie);
}

Liste ListPythonToC (PyObject *List)
{
    Liste lst;
    lst.Taille = PyList_GET_SIZE(List);
    lst.Tableau = malloc(lst.Taille*sizeof(double));
    double temp1;
    for (int i=0;i < lst.Taille; i++)
    {
        temp1 = PyFloat_AsDouble(PyList_GetItem(List, i ));
        lst.Tableau[i] = temp1;
    }
    return(lst);
}

PyObject* ListCToPython (Liste lst)
{
    PyObject *result = PyList_New(lst.Taille);
    PyObject *Affectation;
    for (int i = 0; i< lst.Taille; i++)
    {
        Affectation = PyFloat_FromDouble(lst.Tableau[i]);
        PyList_SetItem(result,i, Affectation);
    }
    return(result);

}

void PrintListMalloc(Liste lst)
{
    for (int i = 0; i< lst.Taille; i++)
    {
        printf("%f",lst.Tableau[i]);
    }
    printf("\n");
}



PyObject* Test_Listes(PyObject* self, PyObject* args)
{
    PyObject *Liste_Py;
    if (!PyArg_ParseTuple(args,"O", &Liste_Py))
    {
        return NULL ;
    }

    Liste lst = ListPythonToC(Liste_Py);

    PrintListMalloc(lst);

    PyObject *result;

    result = ListCToPython(lst);

    return(result);

}
//<================================================================================================================
//<================================================================================================================


PyMethodDef verletFunctions[] = {
    {
        .ml_doc  = "this function prints hello world to the screen",
        .ml_flags= METH_VARARGS,
        .ml_name = "hello",
        .ml_meth = print_hello_world
    },
    {
        .ml_doc  = "this function only does a+b in C with a and b integer T_T",
        .ml_flags= METH_VARARGS,
        .ml_name = "sum_deb",
        .ml_meth = Somme_debilus
    },
    {
        .ml_doc  = "this function only does a+b",
        .ml_flags= METH_VARARGS,
        .ml_name = "sum_two_numbers",
        .ml_meth = Somme
    },
    {
        .ml_doc  = "fait la somme de 2 listes",
        .ml_flags= METH_VARARGS,
        .ml_name = "sum_lists",
        .ml_meth = somme_liste
    },
    {
        .ml_doc  = "fait la soustraction de 2 listes",
        .ml_flags= METH_VARARGS,
        .ml_name = "sub_lists",
        .ml_meth = diff_liste
    },
    {
        .ml_doc  = "multiplie une liste par un flottant",
        .ml_flags= METH_VARARGS,
        .ml_name = "mult_list_by_const",
        .ml_meth = agrandissement
    },
    {
        .ml_doc  = "Fait des trucs lol",
        .ml_flags= METH_VARARGS,
        .ml_name = "Test_Verlet",
        .ml_meth = Test_Verlet
    },
    {
        .ml_doc  = "Encore d'autre trucs",
        .ml_flags= METH_VARARGS,
        .ml_name = "Test_Listes",
        .ml_meth = Test_Listes
    },
    /*{
        .ml_doc  = "Decode une structure point",
        .ml_flags= METH_VARARGS,
        .ml_name = "Decod_Point",
        .ml_meth = Decodage
    },*/
    {NULL, NULL, 0, NULL}
};

// PAS TOUCHER ! =========================================================
PyModuleDef verletModule = {
    .m_base=PyModuleDef_HEAD_INIT,
    .m_doc = "le super module du cours de C",
    .m_name="verlet",
    .m_methods=verletFunctions,
    .m_size=-1
};

PyMODINIT_FUNC PyInit_verlet(){
    PyObject* module;
    
    module = PyModule_Create(&verletModule);
    return module;
}
//=============================================================================
