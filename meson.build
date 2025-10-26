project(
  'schedulers',
  'c',
  meson_version: '>= 1.3.0',
  version: '0.1',
  default_options: ['c_std=c99', 'warning_level=3'],
)

subdir('src')

dependencies = []

exe = executable(
  'schedulers',
  'main.c',
  sources,
  dependencies: dependencies,
  install: true,
)

test('basic', exe)
