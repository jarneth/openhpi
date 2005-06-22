/*      -*- linux-c -*-
 *
 * (C) Copyright IBM Corp. 2004
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Authors:
 *      David Ashley <dashley@us.ibm.com>
 *      Renier Morales <renierm@users.sf.net>
 */

#ifndef __ANNOUNCEMENT_UTILS_H
#define __ANNOUNCEMENT_UTILS_H

#ifndef __OH_UTILS_H
#warning *** Include oh_utils.h instead of individual utility header files ***
#endif

#include <SaHpi.h>
#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OH_ANNOUNCEMENT_MAX_SIZE 0

/* this struct encapsulates all the data for annunciator announcements */
/* the log records themselves are stored in the el GList */
typedef struct {
        SaHpiEventLogEntryIdT nextId; // next generated Id i.e. number of entries
        GList            *annentries; // list of oh_ann_entry structs
} oh_announcement;

/* this structure encapsulates the actual log entry and its context */
typedef struct {
        SaHpiAnnouncementT    annentry;
        SaHpiAnnunciatorNumT  num; // associated annunciator
} oh_ann_entry;

/* General EL utility calls */
oh_announcement *oh_announcement_create(void);
SaErrorT oh_announcement_close(oh_announcement *ann);
SaErrorT oh_announcement_append(oh_announcement *ann,
                                const SaHpiAnnunciatorNumT num,
                                 SaHpiAnnouncementT *myann);
SaErrorT oh_announcement_clear(oh_announcement *ann);
SaErrorT oh_announcement_get(oh_announcement *ann, SaHpiAnnunciatorNumT num,
                             SaHpiEntryIdT srchid, SaHpiAnnouncementT *myann);
SaErrorT oh_announcement_get_next(oh_announcement *ann,
                                  SaHpiAnnunciatorNumT num,
                                  SaHpiAnnouncementT *entry);


#ifdef __cplusplus
}
#endif

#endif