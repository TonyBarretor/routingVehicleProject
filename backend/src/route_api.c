#include "route_api.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Callback function for handling API responses
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    strncat(userp, (char *)contents, total_size);
    return total_size;
}

// Function to query Google Maps API
void get_route(char *response, size_t response_size) {
    const char *api_url = "https://maps.googleapis.com/maps/api/directions/json";
    const char *origin = "37.7749,-122.4194"; // Example origin (San Francisco)
    const char *destination = "34.0522,-118.2437"; // Example destination (Los Angeles)
    const char *api_key = "YOUR_API_KEY"; // Add your API key here

    CURL *curl = curl_easy_init();
    if (curl) {
        char url[512];
        snprintf(url, sizeof(url), "%s?origin=%s&destination=%s&key=%s",
                 api_url, origin, destination, api_key);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
}
