declare -a alllibs
candilib=$(find -type f -name  libgtk-x11-2.0*)
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libgdk-x11-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libpangocairo-1.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libatk-1.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libcairo* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libgdk_pixbuf-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libgio-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libpangoft2-1.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libpango-1.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libgobject-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libglib-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libfontconfig* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libfreetype* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libgthread-2.0* )
    alllibs="${alllibs[@]} ${candilib}"
candilib=$(find -type f -name  libglib-2.0* )
    alllibs="${alllibs[@]} ${candilib}"


    mkdir wantedlibs
    for _libs in ${alllibs[@]}; do
    cp -a ${_libs} wantedlibs/
    done
