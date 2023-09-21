#include <windows.h>
#include <iostream>
#include <string>
#include <curl/curl.h>

// Function to make an HTTP POST request with JSON data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    // This function is called by libcurl as data is received
    return size * nmemb;
}

int main() {
    // Display a dialog box
    MessageBox(NULL, L"You've been Pwned!", L"L331 H4X0R LOLOLOL", MB_OK | MB_ICONINFORMATION);

    // Initialize libcurl
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        // Set the URL of the API endpoint
        const char* url = "https://dsmhgroup.com";

        // Set the JSON data to send in the request
        const char* json_data = "{\"key\": \"value\"}";

        // Set the request method to POST
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(json_data));

        // Perform the HTTP request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    // Clean up libcurl
    curl_global_cleanup();

    return 0;
}
