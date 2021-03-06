{
    "targets": [{
        "target_name": "audio",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        'conditions': [
            ['OS=="mac"', {
                'xcode_settings': {
                    '-std': 'c++11',
                    '-stdlib': 'libc++',
                    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                    'MACOSX_DEPLOYMENT_TARGET': '12.1'
                }
            }]
        ],
        "sources": [
            "cpp/main.cpp",

            # program
            "cpp/src/program.cpp"

        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "/opt/homebrew/include/",
        ],
        'libraries': [
            '-L/opt/homebrew/lib',
            '-lrtaudio',
            '-lfftw3'
        ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
