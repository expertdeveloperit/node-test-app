import { Router } from 'express'
import fact from './factorial'

const router = new Router()

router.use('/fact', fact)

export default router
