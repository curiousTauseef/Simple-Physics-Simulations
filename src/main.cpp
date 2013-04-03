/*
 * main.cpp
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#include <stdlib.h>
#include <string>

using namespace std;

#include "IApplication.h"
#include "ILog.h"

#ifdef ANDROID
#include <android_native_app_glue.h>
int android_main( android_app* application ){
#else
int main( int argc, char* argv[] ){
#endif

	IApplication* app    = NULL;
	ILog*         logger = NULL;

	if(app){
		if( app->initialization() == IApplication::STATUS_SUCCESS ){
			if(logger) logger->put("application init success");
		}else{
			if(logger)
				logger->put("application init fail");
		}
	}else{
		if(logger){
			logger->put("application is null");
		}
	}

#ifdef ANDROID
	return;
#else
	return 0;
#endif
}


