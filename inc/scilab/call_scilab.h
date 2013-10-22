/*
 * Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 * Copyright (C) 2007 - INRIA - Allan CORNET
 * Copyright (C) 2009 - DIGITEO - Allan CORNET
 * Copyright (C) 2010 - DIGITEO - Sylvestre LEDRU
 *
 * This file must be used under the terms of the CeCILL.
 * This source file is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.  The terms
 * are also available at
 * http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#ifndef __CALL_SCILAB_H__
#define __CALL_SCILAB_H__


#ifdef __cplusplus
extern "C" {
#endif

    /*--------------------------------------------------------------------------*/
#include "stack-c.h" /* Provide functions to access to the memory of Scilab */
#include "machine.h"
#include "BOOL.h"
#include "sci_types.h"
    /*--------------------------------------------------------------------------*/

    /**
     * Disable Tcl/Tk and graphic interfaces
     * Scilab no GUI no Tcl/Tk "kernel mode"
     */
    void DisableInteractiveMode(void);

    /**
     * Initialize Scilab
     * @param SCIpath define SCI environment variable : Default --> NULL
     * @param ScilabStartup path & filename of scilab.start : Default --> NULL
     * @param Stacksize : Default --> NULL
     * @return TRUE if it is OK else FALSE
    */
    BOOL StartScilab(char *SCIpath, char *ScilabStartup, int Stacksize);

    /**
     * Start Scilab engine
     * Function created in the context of javasci v2.
     * This function is just like StartScilab but provides more error messages
     * in case or error. For now, it is only used in javasci v2 but it might
     * be public sooner or later.
     * @return
     * 0: success
     * -1: already running
     * -2: Could not find SCI
     * -3: No existing directory
     * Any other positive integer: A Scilab internal error
     */
    int Call_ScilabOpen(char* SCIpath, BOOL advancedMode, char *ScilabStartup, int Stacksize);

    /**
     * Terminate Scilab
     * @param ScilabQuit path & filename of scilab.quit : Default --> NULL
     * @return TRUE if it is OK else FALSE
    */
    BOOL TerminateScilab(char *ScilabQuit);

    /**
     * Send a job to scilab
     * @param job the Scilab Job
     * @return error code operation 0 : OK
    */
    int SendScilabJob(char *job);

    /**
     * Send jobs to scilab
     * @code
     * 	jobs[0] : a = 1;
     * 	jobs[1] : b = 3;
     *	jobs[2] : c = a + b;
     *	SendScilabJobs(jobs,3);
     * @endcode
     * @return last error code operation 0 : OK
    **/
    int SendScilabJobs(char **jobs, int numberjobs);

    /**
     * Returns last job send to scilab by SendScilabJobs or SendScilabJob
     * @param[out] JOB the last job
     * @param[out] nbcharsJOB the size of JOB
     * @code
     * Example :
     * jobs[0] : a = 1;
     * jobs[1] : b = V_NOT_EXIST;
     * jobs[2] : c = a + b;
     * if (SendScilabJobs(jobs,3))
     * {
     * 	char lastjob[4096]; // bsiz in scilab
     *	if (GetLastJob(lastjob,4096))
     *	{
     *		printf("%s\n",lastjob);
     *	}
     * }
     * @endcode
     * @return
    **/
    BOOL GetLastJob(char *JOB, int nbcharsJOB);

    /**
    * This procedure is the entry point to Scilab's event loop
    */
    void ScilabDoOneEvent(void);

    /**
     * Get the information is a graphic windows is opened or not
     * @return Returns TRUE if a graphic windows is opened
    */
    int ScilabHaveAGraph(void);

    /**
     * Return the type of a variable
     * This function is supposed to be used only in the call_scilab context
     *
     * @param varName the variable name
     * @return the type of the variable (the enum is defined in sci_types)
     * Returns -1 when an error occurs -2 when varName cannot be found
     */
    sci_types getVariableType(char *varName);

    /**
     * This function returns the last error code generated by Scilab
     * It should be used to check if a previous command executed by SendScilabJob
     * fail or not
     * @return 0 if no error. Not 0 for an error.
     */
    int getLastErrorValue(void);

    /**
     * This function returns the last error message generated by Scilab
     * It should be used to display the error which occurred
     * @return the error message
     */
    char* getLastErrorMessageSingle(void);

    /********************* DATATYPES MANAGEMENT FUNCTIONS ************/

    /* See the API_scilab documentation See: http://help.scilab.org/api_scilab */
    /* #include "api_scilab.h" */


#ifdef __cplusplus
}
#endif
/*--------------------------------------------------------------------------*/
#endif /* __CALL_SCILAB_H__ */
/*--------------------------------------------------------------------------*/