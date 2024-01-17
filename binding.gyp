{
  'conditions': [
    ['OS=="win"', 
      {
        'targets': [
          {
            'target_name': 'clipboard',
            'sources': [ 'src/cpp/*.cpp' ],
            'include_dirs': [
              '<!(node -e "require(\'nan\')")'
            ],
            'configurations': {
              'Release': {
                'msvs_settings': {
                  'VCCLCompilerTool': {
                    'ExceptionHandling': 1
                  }
                }
              }
            }
          }
        ]
      }
    ],
    ['OS=="mac"', 
      {
        'targets': [
          {
            'target_name': 'clipboard',
            'sources': [ 'src/cppmock/*.cpp' ],
            'include_dirs': [
              '<!(node -e "require(\'nan\')")'
            ],
            'cflags_cc!': [ '-fno-rtti' ],
            'xcode_settings': {
              'GCC_ENABLE_CPP_RTTI': 'YES'
            }
          }
        ]
      }
    ],
    ['OS=="linux"', 
      {
        'targets': [
          {
            'target_name': 'clipboard',
            'sources': [ 'src/cppmock/*.cpp' ],
            'include_dirs': [
              '<!(node -e "require(\'nan\')")'
            ],
            'cflags_cc!': [ '-fno-rtti' ]
          }
        ]
      }
    ]
  ]
}
