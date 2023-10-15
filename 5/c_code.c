#include <Python.h>
#include <stdlib.h>
int py_func(int x, int num_f)
{
       // Устанавливаем переменную окружения на рабочую директорию 
       setenv("PYTHONPATH",".",1);
       
       // This is a type which contains the information Python needs to treat a pointer to an object as an object.
       // Это тип, который содержит информацию, необходимую Python для обработки указателя на объект как объекта.
       PyObject *pName, *pModule, *pDict, *pFunc1, *pFunc2, *pValue, *presult;

       // Инициализируем Python интерпретатор
       // Вызываем инициализацию до выхова каких-либо пользовательских функций
       Py_Initialize();

       // Создание объекта с именами файлов
       // На вход принимает имя файла, которые необходимо загнать в интерпретатор
       pName = PyUnicode_FromString("py_file");
       
       // Print a standard traceback to sys.stderr and clear the error indicator. 
       // Unless the error is a SystemExit, in that case no traceback is printed 
       // and the Python process will exit with the error code specified by the SystemExit instance
       // При возникновении ошибки данная функция не позволит упасть всей симуляции в segmantation fault
       PyErr_Print(); 
       
       // This is a higher-level interface that calls the current “import hook function”
       pModule = PyImport_Import(pName);
       PyErr_Print();

       // pDict is a borrowed reference 
       // Return the dictionary object that implements module’s namespace; 
       // this object is the same as the __dict__ attribute of the module object.
       // Составляем словарь с имеющимися функциями в файле py_file.py
       pDict = PyModule_GetDict(pModule);
       PyErr_Print();

       // pFunc is also a borrowed reference 
       // Присваиваем указатели на конкретные функции
       pFunc1 = PyDict_GetItemString(pDict, (char*)"Python_Function_add");
       pFunc2 = PyDict_GetItemString(pDict, (char*)"Python_Function_pow_two");

       // int PyCallable_Check(PyObject *o)
       // Determine if the object o is callable.
       // Return 1 if the object is callable and 0 otherwise. This function always succeeds.
       // В зависимости от того, какую функцию вызывают выполняем тот или иной if, else
       if(num_f == 0)
       {
              if (PyCallable_Check(pFunc1))
              {
                     // PyObject *Py_BuildValue(const char *format, ...)
                     // Create a new value based on a format string similar to those accepted by the PyArg_Parse* 
                     // family of functions and a sequence of values.
                     pValue=Py_BuildValue("(zi)",(char*)"Python_Function_add", x);
                     PyErr_Print();
                     // printf("Let's give this a shot! x = %d\n", x);
                     presult=PyObject_CallObject(pFunc1,pValue);
                     PyErr_Print();
              } else 
                     PyErr_Print();
       }
       else if(num_f == 1) 
       {
              if (PyCallable_Check(pFunc2))
              {
                     // PyObject *Py_BuildValue(const char *format, ...)
                     // Create a new value based on a format string similar to those accepted by the PyArg_Parse* 
                     // family of functions and a sequence of values.
                     pValue=Py_BuildValue("(zi)",(char*)"Python_Function_pow_two", x);
                     PyErr_Print();
                     // printf("Let's give this a shot! x = %d\n", x);
                     presult=PyObject_CallObject(pFunc2,pValue);
                     PyErr_Print();
              } else 
                     PyErr_Print();
       } 
       else {
              printf("Error! There is no function %x", num_f);
       }

       // Return a C long representation of obj. If obj is not an instance of PyLongObject
       printf("Result is %d\n",(unsigned int)PyLong_AsLong(presult));
       
       // Clean up
       // Высвобождаем занимаемую память
       Py_DECREF(pValue);
       Py_DECREF(pModule);
       Py_DECREF(pName);

       
       // каждый раз завершаем интерпретатор
       Py_Finalize();
       return (unsigned int)PyLong_AsLong(presult);
}