#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <string.h>

/**
 * print_python_bytes - Prints info about Python bytes objects
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;

    setbuf(stdout, NULL);
    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    str = ((PyBytesObject *)p)->ob_sval;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str);
    printf("  first %zd bytes:", size < 10 ? size + 1 : 10);
    for (i = 0; i < (size < 10 ? size + 1 : 10); i++)
        printf(" %02x", (unsigned char)str[i]);
    printf("\n");
}

/**
 * print_python_float - Prints info about Python float objects
 * @p: PyObject pointer
 */
void print_python_float(PyObject *p)
{
    char *str;

    setbuf(stdout, NULL);
    printf("[.] float object info\n");

    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    str = PyOS_double_to_string(((PyFloatObject *)p)->ob_fval, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    printf("  value: %s\n", str);
    PyMem_Free(str);
}

/**
 * print_python_list - Prints info about Python list objects
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, alloc, i;
    PyObject *item;

    setbuf(stdout, NULL);
    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", alloc);

    for (i = 0; i < size; i++)
    {
        item = ((PyListObject *)p)->ob_item[i];
        printf("Element %zd: %s\n", i, item->ob_type->tp_name);

        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
    }
}

