while((ch = fgetc(inputFile))!= EOF){
        if(!inIdentifier){
            if(isValidIdentifierStart(ch)){
                inIdentifier = 1;