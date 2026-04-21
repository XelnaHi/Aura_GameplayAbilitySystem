# Notes / Mind Map

### GameplayEffect
Modifes an attribute. Very versatile featuring, featuring many editable props such as duration, magnitude, tag applications, etc.

### GameplayEffectContext
Useful when you want to know who caused an effect, who the target was, etc. You can use GEC to trace the effect back to its origin.

### GameplayEffectContextHandle
A memory efficient way of passing around the desired `GameplayEffectContext`. Basically stores a weak pointer to a `FGameplayEffectContext`, as well as a lot of useful functions related to the context.
