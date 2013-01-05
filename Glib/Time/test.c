#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <glib.h>

int TimeChangeLocal()
{
    char oldTz[256] = "";

    /* Backup timezone
     */
    char *p = getenv("TZ");
    if (NULL != p) {
        strcpy(oldTz, p);
    }

    /* Change timezone to London time
     */
    setenv("TZ", "Europe/London", 1);

    GDateTime *now = g_date_time_new_now_local();

    /* Check if it's day light saving time.
     */
    if (TRUE == g_date_time_is_daylight_savings(now)) {
        printf("Summer Time. ");
    } else {
        printf("Winter Time. ");
    }

    /* Check current time.
     */
    printf("Europe Now: %04d%02d%02d-%02d:%02d:%02d\n",
           g_date_time_get_year(now),
           g_date_time_get_month(now),
           g_date_time_get_day_of_month(now),
           g_date_time_get_hour(now),
           g_date_time_get_minute(now),
           g_date_time_get_second(now));

    /* Add 8 days * 24 hours * 60 minutes * 60 seconds to current time.
     * and check how time is affected.
     */
    GDateTime *addSec = g_date_time_add_seconds(now, 691200);

    if (TRUE == g_date_time_is_daylight_savings(addSec)) {
        printf("Summer Time. ");
    } else {
        printf("Winter Time. ");
    }

    /* Check the time after changes.
     */
    printf("Europe Add 8 Days: %04d%02d%02d-%02d:%02d:%02d\n",
           g_date_time_get_year(addSec),
           g_date_time_get_month(addSec),
           g_date_time_get_day_of_month(addSec),
           g_date_time_get_hour(addSec),
           g_date_time_get_minute(addSec),
           g_date_time_get_second(addSec));

    g_date_time_unref(now);
    g_date_time_unref(addSec);
    setenv("TZ", oldTz, 1);
}

int TimeForTimeZone()
{
    GTimeZone *london = g_time_zone_new("-0500");
    GDateTime *now = g_date_time_new_now(london);

    /* Check if it's day light saving time.
     */
    if (TRUE == g_date_time_is_daylight_savings(now)) {
        printf("Summer Time. ");
    } else {
        printf("Winter Time. ");
    }

    /* Check current time.
     */
    printf("Europe Now: %04d%02d%02d-%02d:%02d:%02d\n",
           g_date_time_get_year(now),
           g_date_time_get_month(now),
           g_date_time_get_day_of_month(now),
           g_date_time_get_hour(now),
           g_date_time_get_minute(now),
           g_date_time_get_second(now));

    /* Add 8 days * 24 hours * 60 minutes * 60 seconds to current time.
     * and check how time is affected.
     */
    GDateTime *addSec = g_date_time_add_seconds(now, 691200);

    if (TRUE == g_date_time_is_daylight_savings(addSec)) {
        printf("Summer Time. ");
    } else {
        printf("Winter Time. ");
    }

    /* Check the time after changes.
     */
    printf("Europe Add 8 Days: %04d%02d%02d-%02d:%02d:%02d\n",
           g_date_time_get_year(addSec),
           g_date_time_get_month(addSec),
           g_date_time_get_day_of_month(addSec),
           g_date_time_get_hour(addSec),
           g_date_time_get_minute(addSec),
           g_date_time_get_second(addSec));

    g_date_time_unref(now);
    g_date_time_unref(addSec);
}

int main()
{
    printf("\n");
    TimeForTimeZone();
    printf("\n");
    TimeChangeLocal();
    printf("\n");

    return 0;
}
