#define PY_SSIZE_T_CLEAN
#include <Python.h>

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
