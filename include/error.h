
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is libguac.
 *
 * The Initial Developer of the Original Code is
 * Michael Jumper.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef _GUAC_ERROR_H
#define _GUAC_ERROR_H

/**
 * Provides functions and structures required for handling return values and
 * errors.
 *
 * @file error.h
 */

/**
 * Return codes shared by all Guacamole functions which can fail.
 */
typedef enum guac_status {

    /**
     * No errors occurred and the operation was successful.
     */
    GUAC_STATUS_SUCCESS = 0,

    /**
     * Insufficient memory to complete the operation.
     */
    GUAC_STATUS_NO_MEMORY,

    /**
     * The end of the input stream associated with the operation
     * has been reached.
     */
    GUAC_STATUS_NO_INPUT,

    /**
     * No data could be read from an input stream, but data may be available
     * if the operation is retried.
     */
    GUAC_STATUS_INPUT_UNAVAILABLE,

    /**
     * A timeout occurred while reading from the input stream associated
     * with the operation.
     */
    GUAC_STATUS_INPUT_TIMEOUT,

    /**
     * An error prevented the operation from writing to its associated
     * output stream.
     */
    GUAC_STATUS_OUTPUT_ERROR,

    /**
     * The operation could not be performed because an invalid argument was
     * given.
     */
    GUAC_STATUS_BAD_ARGUMENT,

    /**
     * The state of the associated system prevents an operation from being
     * performed which would otherwise be allowed.
     */
    GUAC_STATUS_BAD_STATE

} guac_status;

/**
 * Returns a human-readable explanation of the status code given.
 */
const char* guac_status_string(guac_status status);

#define guac_error (*__guac_error())

guac_status* __guac_error();

#endif
