# ==============
# Define variables
# ==============

# shader files
set(SHADER_SOURCE
"${CMAKE_CURRENT_SOURCE_DIR}/Basic.metal")

# Intermidiate compiled shader
set(SHADER_AIR
"${CMAKE_CURRENT_BINARY_DIR}/Basic.air")

# Final metal library
set(SHADER_LIBRARY
"${CMAKE_CURRENT_BINARY_DIR}/Kinetis.metallib")

add_custom_command(
        OUTPUT "${SHADER_AIR}"

        COMMAND xcrun -sdk macosx metal
        -c "${SHADER_SOURCE}"
        -o "${SHADER_AIR}"

        DEPENDS "${SHADER_SOURCE}"
        VERBATIM
)

add_custom_command(
        OUTPUT "${SHADER_LIBRARY}"

        COMMAND xcrun -sdk macosx metallib
        "${SHADER_AIR}"
        -o "${SHADER_LIBRARY}"

        DEPENDS "${SHADER_AIR}"
        VERBATIM
)

add_custom_target(KinetisShaders
        DEPENDS "${SHADER_LIBRARY}"
)

set(KINETIS_METALLIB
        "${SHADER_LIBRARY}"
        PARENT_SCOPE
)