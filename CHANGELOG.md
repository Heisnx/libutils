# Changelog

## [v1.0.2] - 30/10/2024
### Changes
- Removed `bubble_sort()`.
- Updated `fetch_array()` to accommodate both integers and doubles.
- Merged `fetch_int()` and `fetch_dbl()` into `fetch_number()`.
- Set `MIN` to -1000 and `MAX` to 1000.
- Updated `BUFFER` size to 128.

### Considerations
- Splitting `utils.h` into multiple header files in the future.

### Warnings
- If you are using an older version of this library, switching to a newer version may cause compatibility issues. Please read the changelog before upgrading.
