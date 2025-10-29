project(
  'schedulers',
  'c',
  meson_version: '>= 1.3.0',
  version: '0.1',
  default_options: ['c_std=c99', 'warning_level=3', 'march=generic-v3'],
)

subdir('src')

executable('schedulers', sources, include_directories: include_directories('include'))
