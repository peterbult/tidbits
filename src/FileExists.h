//
//  FileExists.h
//  Custom Headers
//
//  Created by PM Bult on 11-11-11.
//  Copyright 2011 P.M. Bult. All rights reserved.
//
//  Version 1.0
//

#ifndef FileExists_h
#define FileExists_h

namespace {
    bool FileExists( const char* FileName ){
        FILE* fp = NULL;
        
        fp = fopen( FileName, "rb" );
        if( fp != NULL ) {
            fclose( fp );
            return true;
        }
        
        return false;
    }
}

#endif /* FileExists_h */
