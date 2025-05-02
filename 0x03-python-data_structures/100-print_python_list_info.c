#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <stdio.h>

/**
 * print_python_list_info - prints basic info about Python lists
 * @p: Python object passed from Python interpreter
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t i;
    Py_ssize_t list_len;
    PyListObject *list;

    if (!PyList_Check(p))
        return;

    list = (PyListObject *)p;
    list_len = Py_SIZE(p);

    printf("[*] Size of the Python List = %zd\n", list_len);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (i = 0; i < list_len; i++)
    {
        PyObject *item = PyList_GET_ITEM(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
    }
}
