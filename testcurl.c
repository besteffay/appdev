#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>

#define URL "http://www.cc.puv.fi/~gc/php/raspsound.php"

int main(void)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=Yana Dobretsova&ID=e1900301");
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", 
				curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return 0;
}


// To send information from a web-client to a web-server, you should use 
// 	either HTTP get, or HTTP post method.

// A post message is always organized in following format:

// "fields_name1=value1&field_name2=value2..."

// On the server side, if we are using PHP program to receive this
//	"fields=values", you always can do it by 

// $variable = $_POST["field_name1"];	// value1 is given to $variable
